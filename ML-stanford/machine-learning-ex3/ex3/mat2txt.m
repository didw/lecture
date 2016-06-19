Data = load('ex3weights.mat');
DataField = fieldnames(Data);
dlmwrite('ex3Theta1.txt', Data.(DataField{1}));
dlmwrite('ex3Theta2.txt', Data.(DataField{2}));
