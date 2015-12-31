Data = load('ex4data1.mat');
DataField = fieldnames(Data);
dlmwrite('ex4data1.txt', Data.(DataField{1}));
dlmwrite('ex4data2.txt', Data.(DataField{2}));
