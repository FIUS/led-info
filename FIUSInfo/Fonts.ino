
//void setup(){}
//void loop(){}
char font[100][6 * 8];

void initFont() {
/*A*/font[65][0]=0;font[65][1]=1;font[65][2]=1;font[65][3]=1;font[65][4]=1;font[65][5]=1;font[65][6]=1;font[65][7]=0;font[65][8]=0;font[65][9]=0;font[65][10]=0;font[65][11]=0;font[65][12]=1;font[65][13]=0;font[65][14]=0;font[65][15]=1;font[65][16]=1;font[65][17]=0;font[65][18]=0;font[65][19]=1;font[65][20]=0;font[65][21]=0;font[65][22]=0;font[65][23]=0;font[65][24]=0;font[65][25]=0;font[65][26]=0;font[65][27]=0;font[65][28]=1;font[65][29]=0;font[65][30]=0;font[65][31]=1;font[65][32]=0;font[65][33]=1;font[65][34]=1;font[65][35]=1;font[65][36]=1;font[65][37]=1;font[65][38]=1;font[65][39]=0;;
/*B*/font[66][0]=1;font[66][1]=1;font[66][2]=1;font[66][3]=1;font[66][4]=1;font[66][5]=1;font[66][6]=1;font[66][7]=0;font[66][8]=0;font[66][9]=1;font[66][10]=0;font[66][11]=0;font[66][12]=1;font[66][13]=0;font[66][14]=0;font[66][15]=1;font[66][16]=1;font[66][17]=0;font[66][18]=0;font[66][19]=1;font[66][20]=0;font[66][21]=0;font[66][22]=1;font[66][23]=0;font[66][24]=0;font[66][25]=1;font[66][26]=0;font[66][27]=0;font[66][28]=1;font[66][29]=0;font[66][30]=0;font[66][31]=1;font[66][32]=0;font[66][33]=1;font[66][34]=1;font[66][35]=0;font[66][36]=1;font[66][37]=1;font[66][38]=0;font[66][39]=0;;
/*C*/font[67][0]=0;font[67][1]=1;font[67][2]=1;font[67][3]=1;font[67][4]=1;font[67][5]=1;font[67][6]=0;font[67][7]=0;font[67][8]=0;font[67][9]=1;font[67][10]=0;font[67][11]=0;font[67][12]=0;font[67][13]=0;font[67][14]=0;font[67][15]=1;font[67][16]=1;font[67][17]=0;font[67][18]=0;font[67][19]=0;font[67][20]=0;font[67][21]=0;font[67][22]=1;font[67][23]=0;font[67][24]=0;font[67][25]=1;font[67][26]=0;font[67][27]=0;font[67][28]=0;font[67][29]=0;font[67][30]=0;font[67][31]=1;font[67][32]=0;font[67][33]=1;font[67][34]=0;font[67][35]=0;font[67][36]=0;font[67][37]=1;font[67][38]=0;font[67][39]=0;;
/*D*/font[68][0]=1;font[68][1]=1;font[68][2]=1;font[68][3]=1;font[68][4]=1;font[68][5]=1;font[68][6]=1;font[68][7]=0;font[68][8]=0;font[68][9]=1;font[68][10]=0;font[68][11]=0;font[68][12]=0;font[68][13]=0;font[68][14]=0;font[68][15]=1;font[68][16]=1;font[68][17]=0;font[68][18]=0;font[68][19]=0;font[68][20]=0;font[68][21]=0;font[68][22]=1;font[68][23]=0;font[68][24]=0;font[68][25]=1;font[68][26]=0;font[68][27]=0;font[68][28]=0;font[68][29]=0;font[68][30]=0;font[68][31]=1;font[68][32]=0;font[68][33]=1;font[68][34]=1;font[68][35]=1;font[68][36]=1;font[68][37]=1;font[68][38]=0;font[68][39]=0;;
/*E*/font[69][0]=1;font[69][1]=1;font[69][2]=1;font[69][3]=1;font[69][4]=1;font[69][5]=1;font[69][6]=1;font[69][7]=0;font[69][8]=0;font[69][9]=1;font[69][10]=0;font[69][11]=0;font[69][12]=1;font[69][13]=0;font[69][14]=0;font[69][15]=1;font[69][16]=1;font[69][17]=0;font[69][18]=0;font[69][19]=1;font[69][20]=0;font[69][21]=0;font[69][22]=1;font[69][23]=0;font[69][24]=0;font[69][25]=1;font[69][26]=0;font[69][27]=0;font[69][28]=1;font[69][29]=0;font[69][30]=0;font[69][31]=1;font[69][32]=1;font[69][33]=0;font[69][34]=0;font[69][35]=0;font[69][36]=0;font[69][37]=0;font[69][38]=1;font[69][39]=0;;
/*F*/font[70][0]=1;font[70][1]=1;font[70][2]=1;font[70][3]=1;font[70][4]=1;font[70][5]=1;font[70][6]=1;font[70][7]=0;font[70][8]=0;font[70][9]=0;font[70][10]=0;font[70][11]=0;font[70][12]=1;font[70][13]=0;font[70][14]=0;font[70][15]=1;font[70][16]=1;font[70][17]=0;font[70][18]=0;font[70][19]=1;font[70][20]=0;font[70][21]=0;font[70][22]=0;font[70][23]=0;font[70][24]=0;font[70][25]=0;font[70][26]=0;font[70][27]=0;font[70][28]=1;font[70][29]=0;font[70][30]=0;font[70][31]=1;font[70][32]=1;font[70][33]=0;font[70][34]=0;font[70][35]=0;font[70][36]=0;font[70][37]=0;font[70][38]=0;font[70][39]=0;;
/*G*/font[71][0]=0;font[71][1]=1;font[71][2]=1;font[71][3]=1;font[71][4]=1;font[71][5]=1;font[71][6]=0;font[71][7]=0;font[71][8]=0;font[71][9]=1;font[71][10]=0;font[71][11]=0;font[71][12]=0;font[71][13]=0;font[71][14]=0;font[71][15]=1;font[71][16]=1;font[71][17]=0;font[71][18]=0;font[71][19]=0;font[71][20]=0;font[71][21]=0;font[71][22]=1;font[71][23]=0;font[71][24]=0;font[71][25]=1;font[71][26]=0;font[71][27]=1;font[71][28]=0;font[71][29]=0;font[71][30]=0;font[71][31]=1;font[71][32]=0;font[71][33]=1;font[71][34]=0;font[71][35]=0;font[71][36]=1;font[71][37]=1;font[71][38]=0;font[71][39]=0;;
/*H*/font[72][0]=1;font[72][1]=1;font[72][2]=1;font[72][3]=1;font[72][4]=1;font[72][5]=1;font[72][6]=1;font[72][7]=0;font[72][8]=0;font[72][9]=0;font[72][10]=0;font[72][11]=0;font[72][12]=1;font[72][13]=0;font[72][14]=0;font[72][15]=0;font[72][16]=0;font[72][17]=0;font[72][18]=0;font[72][19]=1;font[72][20]=0;font[72][21]=0;font[72][22]=0;font[72][23]=0;font[72][24]=0;font[72][25]=0;font[72][26]=0;font[72][27]=0;font[72][28]=1;font[72][29]=0;font[72][30]=0;font[72][31]=0;font[72][32]=1;font[72][33]=1;font[72][34]=1;font[72][35]=1;font[72][36]=1;font[72][37]=1;font[72][38]=1;font[72][39]=0;;
/*I*/font[73][0]=0;font[73][1]=0;font[73][2]=0;font[73][3]=0;font[73][4]=0;font[73][5]=0;font[73][6]=0;font[73][7]=0;font[73][8]=0;font[73][9]=1;font[73][10]=0;font[73][11]=0;font[73][12]=0;font[73][13]=0;font[73][14]=0;font[73][15]=1;font[73][16]=1;font[73][17]=1;font[73][18]=1;font[73][19]=1;font[73][20]=1;font[73][21]=1;font[73][22]=1;font[73][23]=0;font[73][24]=0;font[73][25]=1;font[73][26]=0;font[73][27]=0;font[73][28]=0;font[73][29]=0;font[73][30]=0;font[73][31]=1;font[73][32]=0;font[73][33]=0;font[73][34]=0;font[73][35]=0;font[73][36]=0;font[73][37]=0;font[73][38]=0;font[73][39]=0;;
/*J*/font[74][0]=0;font[74][1]=0;font[74][2]=0;font[74][3]=0;font[74][4]=0;font[74][5]=1;font[74][6]=0;font[74][7]=0;font[74][8]=0;font[74][9]=1;font[74][10]=0;font[74][11]=0;font[74][12]=0;font[74][13]=0;font[74][14]=0;font[74][15]=1;font[74][16]=1;font[74][17]=0;font[74][18]=0;font[74][19]=0;font[74][20]=0;font[74][21]=0;font[74][22]=1;font[74][23]=0;font[74][24]=0;font[74][25]=1;font[74][26]=0;font[74][27]=0;font[74][28]=0;font[74][29]=0;font[74][30]=0;font[74][31]=1;font[74][32]=1;font[74][33]=1;font[74][34]=1;font[74][35]=1;font[74][36]=1;font[74][37]=1;font[74][38]=0;font[74][39]=0;;
/*K*/font[75][0]=1;font[75][1]=1;font[75][2]=1;font[75][3]=1;font[75][4]=1;font[75][5]=1;font[75][6]=1;font[75][7]=0;font[75][8]=0;font[75][9]=0;font[75][10]=0;font[75][11]=0;font[75][12]=1;font[75][13]=0;font[75][14]=0;font[75][15]=0;font[75][16]=0;font[75][17]=0;font[75][18]=1;font[75][19]=0;font[75][20]=1;font[75][21]=0;font[75][22]=0;font[75][23]=0;font[75][24]=0;font[75][25]=0;font[75][26]=1;font[75][27]=0;font[75][28]=0;font[75][29]=0;font[75][30]=1;font[75][31]=0;font[75][32]=1;font[75][33]=0;font[75][34]=0;font[75][35]=0;font[75][36]=0;font[75][37]=0;font[75][38]=1;font[75][39]=0;;
/*L*/font[76][0]=1;font[76][1]=1;font[76][2]=1;font[76][3]=1;font[76][4]=1;font[76][5]=1;font[76][6]=1;font[76][7]=0;font[76][8]=0;font[76][9]=1;font[76][10]=0;font[76][11]=0;font[76][12]=0;font[76][13]=0;font[76][14]=0;font[76][15]=0;font[76][16]=0;font[76][17]=0;font[76][18]=0;font[76][19]=0;font[76][20]=0;font[76][21]=0;font[76][22]=1;font[76][23]=0;font[76][24]=0;font[76][25]=1;font[76][26]=0;font[76][27]=0;font[76][28]=0;font[76][29]=0;font[76][30]=0;font[76][31]=0;font[76][32]=0;font[76][33]=0;font[76][34]=0;font[76][35]=0;font[76][36]=0;font[76][37]=0;font[76][38]=1;font[76][39]=0;;
/*M*/font[77][0]=1;font[77][1]=1;font[77][2]=1;font[77][3]=1;font[77][4]=1;font[77][5]=1;font[77][6]=1;font[77][7]=0;font[77][8]=0;font[77][9]=0;font[77][10]=0;font[77][11]=0;font[77][12]=0;font[77][13]=0;font[77][14]=1;font[77][15]=0;font[77][16]=0;font[77][17]=0;font[77][18]=1;font[77][19]=0;font[77][20]=0;font[77][21]=0;font[77][22]=0;font[77][23]=0;font[77][24]=0;font[77][25]=0;font[77][26]=0;font[77][27]=0;font[77][28]=0;font[77][29]=0;font[77][30]=1;font[77][31]=0;font[77][32]=1;font[77][33]=1;font[77][34]=1;font[77][35]=1;font[77][36]=1;font[77][37]=1;font[77][38]=1;font[77][39]=0;;
/*N*/font[78][0]=1;font[78][1]=1;font[78][2]=1;font[78][3]=1;font[78][4]=1;font[78][5]=1;font[78][6]=1;font[78][7]=0;font[78][8]=0;font[78][9]=0;font[78][10]=0;font[78][11]=0;font[78][12]=0;font[78][13]=1;font[78][14]=0;font[78][15]=0;font[78][16]=0;font[78][17]=0;font[78][18]=0;font[78][19]=1;font[78][20]=0;font[78][21]=0;font[78][22]=0;font[78][23]=0;font[78][24]=0;font[78][25]=0;font[78][26]=0;font[78][27]=1;font[78][28]=0;font[78][29]=0;font[78][30]=0;font[78][31]=0;font[78][32]=1;font[78][33]=1;font[78][34]=1;font[78][35]=1;font[78][36]=1;font[78][37]=1;font[78][38]=1;font[78][39]=0;;
/*O*/font[79][0]=0;font[79][1]=1;font[79][2]=1;font[79][3]=1;font[79][4]=1;font[79][5]=1;font[79][6]=0;font[79][7]=0;font[79][8]=0;font[79][9]=1;font[79][10]=0;font[79][11]=0;font[79][12]=0;font[79][13]=0;font[79][14]=0;font[79][15]=1;font[79][16]=1;font[79][17]=0;font[79][18]=0;font[79][19]=0;font[79][20]=0;font[79][21]=0;font[79][22]=1;font[79][23]=0;font[79][24]=0;font[79][25]=1;font[79][26]=0;font[79][27]=0;font[79][28]=0;font[79][29]=0;font[79][30]=0;font[79][31]=1;font[79][32]=0;font[79][33]=1;font[79][34]=1;font[79][35]=1;font[79][36]=1;font[79][37]=1;font[79][38]=0;font[79][39]=0;;
/*P*/font[80][0]=1;font[80][1]=1;font[80][2]=1;font[80][3]=1;font[80][4]=1;font[80][5]=1;font[80][6]=1;font[80][7]=0;font[80][8]=0;font[80][9]=0;font[80][10]=0;font[80][11]=0;font[80][12]=1;font[80][13]=0;font[80][14]=0;font[80][15]=1;font[80][16]=1;font[80][17]=0;font[80][18]=0;font[80][19]=1;font[80][20]=0;font[80][21]=0;font[80][22]=0;font[80][23]=0;font[80][24]=0;font[80][25]=0;font[80][26]=0;font[80][27]=0;font[80][28]=1;font[80][29]=0;font[80][30]=0;font[80][31]=1;font[80][32]=0;font[80][33]=1;font[80][34]=1;font[80][35]=0;font[80][36]=0;font[80][37]=0;font[80][38]=0;font[80][39]=0;;
/*Q*/font[81][0]=0;font[81][1]=1;font[81][2]=1;font[81][3]=1;font[81][4]=1;font[81][5]=1;font[81][6]=0;font[81][7]=0;font[81][8]=0;font[81][9]=1;font[81][10]=0;font[81][11]=0;font[81][12]=0;font[81][13]=0;font[81][14]=0;font[81][15]=1;font[81][16]=1;font[81][17]=0;font[81][18]=0;font[81][19]=0;font[81][20]=1;font[81][21]=0;font[81][22]=1;font[81][23]=0;font[81][24]=0;font[81][25]=0;font[81][26]=1;font[81][27]=0;font[81][28]=0;font[81][29]=0;font[81][30]=0;font[81][31]=1;font[81][32]=0;font[81][33]=1;font[81][34]=1;font[81][35]=1;font[81][36]=1;font[81][37]=0;font[81][38]=1;font[81][39]=0;;
/*R*/font[82][0]=1;font[82][1]=1;font[82][2]=1;font[82][3]=1;font[82][4]=1;font[82][5]=1;font[82][6]=1;font[82][7]=0;font[82][8]=0;font[82][9]=0;font[82][10]=0;font[82][11]=0;font[82][12]=1;font[82][13]=0;font[82][14]=0;font[82][15]=1;font[82][16]=1;font[82][17]=0;font[82][18]=0;font[82][19]=1;font[82][20]=0;font[82][21]=0;font[82][22]=0;font[82][23]=0;font[82][24]=0;font[82][25]=0;font[82][26]=0;font[82][27]=0;font[82][28]=1;font[82][29]=0;font[82][30]=0;font[82][31]=1;font[82][32]=0;font[82][33]=1;font[82][34]=1;font[82][35]=0;font[82][36]=1;font[82][37]=1;font[82][38]=1;font[82][39]=0;;
/*S*/font[83][0]=0;font[83][1]=1;font[83][2]=1;font[83][3]=0;font[83][4]=0;font[83][5]=1;font[83][6]=0;font[83][7]=0;font[83][8]=0;font[83][9]=1;font[83][10]=0;font[83][11]=0;font[83][12]=1;font[83][13]=0;font[83][14]=0;font[83][15]=1;font[83][16]=1;font[83][17]=0;font[83][18]=0;font[83][19]=1;font[83][20]=0;font[83][21]=0;font[83][22]=1;font[83][23]=0;font[83][24]=0;font[83][25]=1;font[83][26]=0;font[83][27]=0;font[83][28]=1;font[83][29]=0;font[83][30]=0;font[83][31]=1;font[83][32]=0;font[83][33]=1;font[83][34]=0;font[83][35]=0;font[83][36]=1;font[83][37]=1;font[83][38]=0;font[83][39]=0;;
/*T*/font[84][0]=1;font[84][1]=0;font[84][2]=0;font[84][3]=0;font[84][4]=0;font[84][5]=0;font[84][6]=0;font[84][7]=0;font[84][8]=0;font[84][9]=0;font[84][10]=0;font[84][11]=0;font[84][12]=0;font[84][13]=0;font[84][14]=0;font[84][15]=1;font[84][16]=1;font[84][17]=1;font[84][18]=1;font[84][19]=1;font[84][20]=1;font[84][21]=1;font[84][22]=1;font[84][23]=0;font[84][24]=0;font[84][25]=0;font[84][26]=0;font[84][27]=0;font[84][28]=0;font[84][29]=0;font[84][30]=0;font[84][31]=1;font[84][32]=1;font[84][33]=0;font[84][34]=0;font[84][35]=0;font[84][36]=0;font[84][37]=0;font[84][38]=0;font[84][39]=0;;
/*U*/font[85][0]=1;font[85][1]=1;font[85][2]=1;font[85][3]=1;font[85][4]=1;font[85][5]=1;font[85][6]=0;font[85][7]=0;font[85][8]=0;font[85][9]=1;font[85][10]=0;font[85][11]=0;font[85][12]=0;font[85][13]=0;font[85][14]=0;font[85][15]=0;font[85][16]=0;font[85][17]=0;font[85][18]=0;font[85][19]=0;font[85][20]=0;font[85][21]=0;font[85][22]=1;font[85][23]=0;font[85][24]=0;font[85][25]=1;font[85][26]=0;font[85][27]=0;font[85][28]=0;font[85][29]=0;font[85][30]=0;font[85][31]=0;font[85][32]=1;font[85][33]=1;font[85][34]=1;font[85][35]=1;font[85][36]=1;font[85][37]=1;font[85][38]=0;font[85][39]=0;;
/*V*/font[86][0]=1;font[86][1]=1;font[86][2]=1;font[86][3]=1;font[86][4]=1;font[86][5]=0;font[86][6]=0;font[86][7]=0;font[86][8]=0;font[86][9]=0;font[86][10]=1;font[86][11]=0;font[86][12]=0;font[86][13]=0;font[86][14]=0;font[86][15]=0;font[86][16]=0;font[86][17]=0;font[86][18]=0;font[86][19]=0;font[86][20]=0;font[86][21]=0;font[86][22]=1;font[86][23]=0;font[86][24]=0;font[86][25]=0;font[86][26]=1;font[86][27]=0;font[86][28]=0;font[86][29]=0;font[86][30]=0;font[86][31]=0;font[86][32]=1;font[86][33]=1;font[86][34]=1;font[86][35]=1;font[86][36]=1;font[86][37]=0;font[86][38]=0;font[86][39]=0;;
/*W*/font[87][0]=1;font[87][1]=1;font[87][2]=1;font[87][3]=1;font[87][4]=1;font[87][5]=1;font[87][6]=0;font[87][7]=0;font[87][8]=0;font[87][9]=1;font[87][10]=0;font[87][11]=0;font[87][12]=0;font[87][13]=0;font[87][14]=0;font[87][15]=0;font[87][16]=0;font[87][17]=0;font[87][18]=0;font[87][19]=0;font[87][20]=0;font[87][21]=1;font[87][22]=0;font[87][23]=0;font[87][24]=0;font[87][25]=1;font[87][26]=0;font[87][27]=0;font[87][28]=0;font[87][29]=0;font[87][30]=0;font[87][31]=0;font[87][32]=1;font[87][33]=1;font[87][34]=1;font[87][35]=1;font[87][36]=1;font[87][37]=1;font[87][38]=0;font[87][39]=0;;
/*X*/font[88][0]=1;font[88][1]=1;font[88][2]=0;font[88][3]=0;font[88][4]=0;font[88][5]=1;font[88][6]=1;font[88][7]=0;font[88][8]=0;font[88][9]=0;font[88][10]=0;font[88][11]=1;font[88][12]=0;font[88][13]=1;font[88][14]=0;font[88][15]=0;font[88][16]=0;font[88][17]=0;font[88][18]=0;font[88][19]=1;font[88][20]=0;font[88][21]=0;font[88][22]=0;font[88][23]=0;font[88][24]=0;font[88][25]=0;font[88][26]=0;font[88][27]=1;font[88][28]=0;font[88][29]=1;font[88][30]=0;font[88][31]=0;font[88][32]=1;font[88][33]=1;font[88][34]=0;font[88][35]=0;font[88][36]=0;font[88][37]=1;font[88][38]=1;font[88][39]=0;;
/*Y*/font[89][0]=1;font[89][1]=1;font[89][2]=0;font[89][3]=0;font[89][4]=0;font[89][5]=0;font[89][6]=0;font[89][7]=0;font[89][8]=0;font[89][9]=0;font[89][10]=0;font[89][11]=0;font[89][12]=0;font[89][13]=1;font[89][14]=0;font[89][15]=0;font[89][16]=0;font[89][17]=0;font[89][18]=0;font[89][19]=1;font[89][20]=1;font[89][21]=1;font[89][22]=1;font[89][23]=0;font[89][24]=0;font[89][25]=0;font[89][26]=0;font[89][27]=0;font[89][28]=0;font[89][29]=1;font[89][30]=0;font[89][31]=0;font[89][32]=1;font[89][33]=1;font[89][34]=0;font[89][35]=0;font[89][36]=0;font[89][37]=0;font[89][38]=0;font[89][39]=0;;
/*Z*/font[90][0]=1;font[90][1]=0;font[90][2]=0;font[90][3]=0;font[90][4]=0;font[90][5]=1;font[90][6]=1;font[90][7]=0;font[90][8]=0;font[90][9]=1;font[90][10]=0;font[90][11]=1;font[90][12]=0;font[90][13]=0;font[90][14]=0;font[90][15]=1;font[90][16]=1;font[90][17]=0;font[90][18]=0;font[90][19]=1;font[90][20]=0;font[90][21]=0;font[90][22]=1;font[90][23]=0;font[90][24]=0;font[90][25]=1;font[90][26]=0;font[90][27]=0;font[90][28]=0;font[90][29]=1;font[90][30]=0;font[90][31]=1;font[90][32]=1;font[90][33]=1;font[90][34]=0;font[90][35]=0;font[90][36]=0;font[90][37]=0;font[90][38]=1;font[90][39]=0;;

}
