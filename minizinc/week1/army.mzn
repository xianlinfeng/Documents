var 100..800:army;

constraint army mod 5 = 2;
constraint army mod 7 = 2;
constraint army mod 12 = 4;

solve satisfy;

