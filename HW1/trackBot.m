%Main Function
%This will return the whole path walked by the robot, final pos and flag
function [P,p_f,flag] = trackBot(p_i,command,varargin)
    %check if last input parameter (Wall) is empty
    if isempty(varargin)
        %set wall to empty and wallGate to false
        W = [];
        wallGate = false;
    else
        %set wall to first parameter of varargin and wallGate to true
        W = varargin{1};
        wallGate = true;
    end
    %wallGate is a boolean that will be used in calculating the path for
    %the robot. If there's no wall, wallGate will be false, and vice versa.
    
    %check flag before calculating
    flag = checkFlag(p_i,command,W);
    
    %flag = 1 means nothing is wrong about the input parameters
    if flag == 1
        %call calculatePath function
        [P,p_f] = calculatePath(p_i,command,W,wallGate);
    else
        %something is wrong w/ the input then output "P" and "p_f" as empty
        %vectors and output the error flag 
        P = [];
        p_f = [];
    end
end

%Function for calculating paths of the robot
%Require p_i(2x1), command(array of char), W(2xn), wallGate(boolean)
%Return P(2xn), p_f(2x1)
function [P,p_f] = calculatePath(p_i,command,W,wallGate)
    %set starting variables
    P = p_i;
    currentPos = p_i;
    %Starting north (x = 0, y = +1)
    stepMatrix = [0;1];  
    %loop check by command's index
    for index = 1 : numel(command)
        %set current action(0,1,2,3,4), 0 is standstill (do nothing)
        currentCommand = command(index);
        %Check all commands
        %Move forward (1)
        if currentCommand == '1' 
            %check wallGate (true if wall is exist, false if wall is not exist)
            if wallGate
                %set checking variable for checking wall
                predictPos = currentPos + stepMatrix;
                %check if predictPos is not in a wall
                if all(ismember(W',predictPos','rows') == 0,'all')
                    %Change currentPosition and update to all Path
                    currentPos = currentPos + stepMatrix;
                    P = [P currentPos];
                end
            %wallGate is false, update position
            else
                currentPos = currentPos + stepMatrix;
                P = [P currentPos];
            end
        %Turn Left (2)
        elseif currentCommand == '2'
            %Rotation with 90 deg
            theta = 90*sym(pi)/180;
            rotationalMatrix = [cos(theta) -sin(theta);sin(theta) cos(theta)];
            stepMatrix = rotationalMatrix*stepMatrix;
        %Turn Right (3)
        elseif currentCommand == '3' 
            %Rotation with -90 deg
            theta = -90*sym(pi)/180;
            rotationalMatrix = [cos(theta) -sin(theta);sin(theta) cos(theta)];
            stepMatrix = rotationalMatrix*stepMatrix;
        %Move Backward (4)
        elseif currentCommand == '4'
            %check wallGate (true if wall is exist, false if wall is not exist)
            if wallGate
                %set checking variable for checking wall
                predictPos = currentPos - stepMatrix;
                %check if predictPos is not in a wall
                if all(ismember(W',predictPos','rows') == 0,'all')
                    %Change currentPosition and update to all Path
                    currentPos = currentPos - stepMatrix;
                    P = [P currentPos];
                end
            %wallGate is false, update current position
            else
                currentPos = currentPos - stepMatrix;
                P = [P currentPos];
            end
        end
    end
    %update final pos (This will run after everything finished calculating)
    P = double(P);
    p_f = double(currentPos);
end

%Function for checking error flags.
%If there aren't any error, it will return flag = 1
function flag = checkFlag(p_i,command,W)
    checkControl = ['0' '1' '2' '3' '4'];
    %check if p_i's size is correct
    if size(p_i,1) == 2 && size(p_i,2) == 1
        %check if any value in p_i is not a whole number
        if not(all(rem(p_i,1) == 0, 'all'))
            flag = -12;
        else
            % check if command is char
            if ischar(command)
                % check if all command input is correct or is empty
                if all(ismember(command,checkControl) == 1, 'all') || isempty(command)
                    %check if W input is not empty
                    if not(isempty(W))
                        %check if W's size is 2xn, since W's columns can be extended
                        %indefinitely there's no need to check the column
                        if size(W,1) == 2
                            %check if there's any memeber of W that aren't whole numbers
                            if not(all(rem(W,1) == 0, 'all'))
                                flag = -32;
                            %every members are whole numbers then do these
                            else
                                %check if initial pos is in a wall
                                if any(ismember(W',p_i','rows'),'all')
                                    flag =  -4;
                                %all inputs are correct (have walls)
                                else
                                    flag = 1;
                                end
                            end
                            %W's size is not 2xn
                        else
                            flag = -31;
                        end
                    else
                        %all inputs are correct (no wall)
                        flag = 1;
                    end
                %command has other char other than '0 1 2 3 4'
                else
                    flag = -22;
                end
            %command is not char
            else
                flag = -21;
            end
        end
    %p_i's size is incorrect
    else
        flag = -11;
    end
end