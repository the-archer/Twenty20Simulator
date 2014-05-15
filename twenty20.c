#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>


float r0, r1, r2, r3, r4, r6;
int runb, ran[2000], r, comm[2000], c, d, ro, runout[2000], dis, dismissal[2000], l;
float btav1, bwav1, bwsr1, bwav2, btsr1, bwsr2, btav2, btsr2 , out1, out, sr2, sr;
char btst[10], btrn[10], bw[10];
char batfnm[20], batlnm[20], bowlfnm[20], bowllnm[20], team1pbowl[20][10], team2pbowl[20][10], bwtypet1[20][10], bwtypet2[20][10];
int i, j, k;
char team1p[20][10], team2p[20][10];
int t1runs, t2runs,m;
char team1pfname[20][20], team1plname[20][20], team2pfname[20][20], team2plname[20][20], fieldlnm[20], wklnm[20], runnerlnm[20];
int wkt1, wkt2;
float pitch;
char t1bord[30], t2bord[30];
char team1[30], team2[30];
FILE *fcomm;





int ballcall(void);
int ballcall2(void);
int ballcall3(void);
int ballcall4(void);
void bowlorder(void);


void comm0p(void);
void comm1p(void);
void comm2p(void);
void comm4p(void);
void comm6(void);
void commw(void);
void comm0s(void);
void comm1s(void);
void comm4s(void);
int main(void)

{
	
	
	

	int  n, r, q,counter=0, counter2=0, counter3=0, counter4=0, w=0, maiden=0, victory=1, mode, bowltype;
	int oruns, fielder, team1dism[12][3]={0}, team2dism[12][3]={0};
	char bt1[5], bt2[5], bw1[5], bw2[5];
	
	char dummy[20];
	int team1pbatrun[12]={0}, team1pball[12]={0}, team1pfour[12]={0}, team1psix[12]={0}, team1pover[12]={0}, team1pmaiden[12]={0}, team1pwicket[12]={0}, team1pbowlrun[12]={0}, team1pcarryover[12]={0} ; 
	int team2pbatrun[12]={0}, team2pball[12]={0}, team2pfour[12]={0}, team2psix[12]={0}, team2pover[12]={0}, team2pmaiden[12]={0}, team2pwicket[12]={0}, team2pbowlrun[12]={0}, team2pcarryover[12]={0} ; 
	int four={0}, six={0};
	char btrnfnm[20], btrnlnm[20];
	char bufferd[20];
	float buffer1d;
	char bwtype[4];
	int mainchoose, teamchoose, statchoose;
	char teamname[50][2][20];
	char space1[1], space2[1], statfile[4];
	int teamwords[50]={0};
	int toss, tosschoose;
	int stmatches, stbatinnings, stbatruns, stbatballs, stbatnouts, stbatfours, stbatsixes, st50s, st100s, stbatbest;
	int stbowlinnings, stbowlballs, stbowlruns, stbowlwickets, st4wkts, st5wkts, stbowlbestw, stbowlbestr;
	char dummy2[20], dummy3[20];
	int dummyint, dummyint2, dummyint3;
	int alpha, t1finw, totteam, beeta={0};
	char bigbuffer[100];
	FILE *t1;
	FILE *t2;
	FILE *bord;
	FILE *btrnf;
	
	FILE *distype;
	FILE *tmlst;
	
	




	
	main:
	system("clear");
	
	strcpy(space2, " ");
	printf("\t\t\t\t\t  Sim's Cricket Sim - Crecc099 \n\n");
	
	usleep(500000);
	printf("\t\t\t\t\t'The beauty of near-perfection.'\n");
	printf("\t\t\t\t\t\t\t\t\t\tVersion 1.1\n\n");
	usleep(500000);
	printf("\n\n\n\n");
	printf("\t\t\t\t\t1. Simulate an ODI Match.\n");
	printf("\t\t\t\t\t2. View Statistics.\n");
	printf("\t\t\t\t\t3. Create/edit teams.\n");
	printf("\t\t\t\t\t4. Help\n");
	printf("\t\t\t\t\t5. Exit\n");
	printf("\n\n\n");
	printf("\t\t\t\t\tEnter your choice : ");

	tmlst=fopen("Data/Teams/teamlist.txt", "r"); //Loading teamnames..
	for(i=1; /*(getc(tmlst))!=EOF*/; i++)
		{
			if((fscanf(tmlst, "%s", teamname[i][0]))<=0)
				break;

			if(getc(tmlst)!='\n')
			{
				fscanf(tmlst, "%s", teamname[i][1]);
				
				strcat(teamname[i][0], space2);
				strcat(teamname[i][0], teamname[i][1]);
					
				
			} 
			
			
		}
	totteam=i;
	fclose(tmlst);	

	scanf("%d", &mainchoose);

	if(mainchoose==1)
	{	
		
		system("clear");
				
		printf("\t\t\t\t\t  Sim's Cricket Sim - Crecc099 \n\n");
		printf("\n\n\n");
		printf("Teams Available:\n\n\n");
		usleep(500000);
		for(i=1; i<totteam ; i++)
		{
			
			printf("%d. %s \n", i, teamname[i][0]);
			
		}
		
		getchar();
		
		printf("\n\n\nEnter S.No. of Team 1 : ");
		scanf("%d", &teamchoose);
		strcpy(team1, teamname[teamchoose][0]);
			
		printf("%s", team1);
		getchar();
		
		printf("\n\n\nEnter S.No. of Team 2 : ");
		scanf("%d", &teamchoose);
		strcpy(team2, teamname[teamchoose][0]);
		

		printf("%s\n\n", team2);
		
		
	}
	

	if(mainchoose==2)
	{

		stat:
		system("clear");
				
		printf("\t\t\t\t\t  Sim's Cricket Sim - Crecc099 \n\n");
		printf("\t\t\t\t\t    Statistics \n\n\n\n");
		printf("\t\t\t\t\t1. View Stats Teamwise.\n");
		printf("\t\t\t\t\t2. View Stats Playerwise.\n");
		printf("\t\t\t\t\t3. View Stats of all players.\n");
		printf("\t\t\t\t\t4. Reset all stats.\n");
		printf("\t\t\t\t\t5. Return to home screen.\n\n\n");
		printf("\t\t\t\t\tEnter your choice : ");
		scanf("%d", &statchoose);
		if(statchoose==1)
		{
			
			system("clear");
			printf("\t\t\t\t\t  Sim's Cricket Sim - Crecc099 \n\n");
			printf("\t\t\t\t\t    Statistics \n\n\n\n");
			for(i=1; i<totteam ; i++)
			{
			
				printf("%d. %s \n", i, teamname[i][0]);
			
			}
			
			printf("Select team : ");
			scanf("%d", &teamchoose);
			FILE *teamstat;
			strcpy(bigbuffer, "Data/Teams/");
			strcat(bigbuffer, (teamname[teamchoose][0]) );
			strcat(bigbuffer, ".txt");
			teamstat=fopen((bigbuffer), "r");
			//printf("%s", bigbuffer);
			printf("\n%s\n",teamname[teamchoose][0]);
			printf("\t\t\t       Batting\t\t\t\t\t\t   Bowling\n");
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
			printf("Player\t\t M   I  NO  Runs   Ave     SR     HS  50s  100s | I    O   Runs    W    Ave   Econ    SR     BBI   4w  5w\n");
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
			getchar();
			for(i=1; ; i++)
			{
				FILE *plstat;
				FILE *plname;
			
				if((fscanf(teamstat, "%s", dummy))<=0)
					break;
				strcpy(bigbuffer, "Data/Players/");
				strcat(bigbuffer, dummy);
				strcat(bigbuffer, ".txt");
				plname=fopen(bigbuffer, "r");
				//printf("%s\n", bigbuffer);
				fscanf(plname, "%s", dummy2);
				fscanf(plname, "%s", dummy3);
				printf("%c ", dummy2[0]);
				printf("%-15s", dummy3);
				strcpy(bigbuffer, "Data/Stats/");
				strcat(bigbuffer, dummy);
				strcat(bigbuffer, "stat");
				strcat(bigbuffer, ".txt");
				
				plstat=fopen(bigbuffer, "r");
				fscanf(plstat, "%d", &stmatches);
				printf("%d  ", stmatches);
				fscanf(plstat, "%d", &stbatinnings);
				printf("%2d   ", stbatinnings);
				fscanf(plstat, "%d", &stbatnouts);
				printf("%d  ", stbatnouts);
				fscanf(plstat, "%d", &stbatruns);
				printf("%3d  ", stbatruns);
				if(stbatinnings==stbatnouts)
				printf("  --    ");
				else
				printf("%6.2f  ", (float)stbatruns/(stbatinnings-stbatnouts)); 				
				fscanf(plstat, "%d", &stbatballs);
				if(stbatballs==0)
				printf("  --    ");
				else
				printf("%6.2f  ", ((float)stbatruns/(float)stbatballs)*100);
				fscanf(plstat, "%d", &stbatbest);
				printf("%3d  ", stbatbest);
				
				fscanf(plstat, "%d", &stbatfours);
				fscanf(plstat, "%d", &stbatsixes);
				fscanf(plstat, "%d", &st50s);
				printf("%2d    ", st50s);
				fscanf(plstat, "%d", &st100s);
				printf("%2d  ", st100s);
				fscanf(plstat, "  %d", &stbowlinnings);
				printf(" %2d  ", stbowlinnings);
				fscanf(plstat, "%d", &stbowlballs);
				printf(" %2d.", stbowlballs/6);
				printf("%d  ", stbowlballs%6);
				fscanf(plstat, "%d", &stbowlruns);
				printf("%3d  ", stbowlruns);
				fscanf(plstat, "%d", &stbowlwickets);
				printf("%3d  ", stbowlwickets);
				if(stbowlwickets==0)
				printf("   --  ");
				else
				printf("%6.2f  ", (float)stbowlruns/stbowlwickets);
				if(stbowlballs==0)
				printf("   --  ");
				else
				printf("%4.2f  ", (float)stbowlruns/stbowlballs*6);
				if(stbowlwickets==0)
				printf("   --  ");
				else
				printf("%6.2f  ", (float)stbowlballs/stbowlwickets);

				fscanf(plstat, "%d", &st4wkts);
				fscanf(plstat, "%d", &st5wkts);
				fscanf(plstat, "%d", &stbowlbestw);
				fscanf(plstat, "%d", &stbowlbestr);
				if(stbowlballs==0)
				printf("   --   ");
				else
				printf("%2d-%2d  ", stbowlbestw, stbowlbestr);
				printf("%2d  ", st4wkts);
				printf("%2d", st5wkts);
				printf("\n");


									
				
				fclose(plstat);
				fclose(plname); 
				
			}
			
			printf("\n\nPress Enter to return back to the Stats menu.");
			getchar();
			fclose(teamstat);
			goto stat;
		}
		if(statchoose==4)
		{
			{          //Used for resetting all stats to 0.
				FILE *temp1;
				FILE *temp2;
		
				for(i=1; i<totteam; i++)
				{	

					strcpy(bigbuffer, "Data/Teams/");
					strcat(bigbuffer,  teamname[i][0]);
					strcat(bigbuffer, ".txt");
					temp1=fopen(bigbuffer, "r");
					for(j=1; j<12; j++)
					{
						fscanf(temp1, "%s", dummy);
						strcpy(bigbuffer, "Data/Stats/");
						strcpy(bigbuffer, dummy);

						strcat(bigbuffer, "stat.txt");
						temp2=fopen(bigbuffer, "w");
						for(k=0; k<18; k++)
						{
							fprintf(temp2,"%d\n", 0);
						}
						fclose(temp2);
					}
				}
				fclose(temp1);
		
			}
			goto main;

		}
		
		if(statchoose==5)
		goto main;

		
	}

	if(mainchoose==5)
	return(0);
	
	/*{         //Used to create -stat suffix files for every player. Can be modified as a function maybe while adding new players.
		FILE *temp1;
		FILE *temp2;
		//strcpy(statfile, "stat");
		for(i=1; i<3; i++)
		{	
			temp1=fopen(teamname[i][0], "r");
			for(j=1; j<12; j++)
			{
				fscanf(temp1, "%s", dummy);
				strcat(dummy, "stat");
				temp2=fopen(dummy, "w");
				fclose(temp2);
			}
			fclose(temp1);
					
		}
	} */

	/*{          //Used for resetting all stats to 0.
		FILE *temp1;
		FILE *temp2;
		
		for(i=1; i<8; i++)
		{	
			temp1=fopen(teamname[i][0], "r");
			for(j=1; j<12; j++)
			{
				fscanf(temp1, "%s", dummy);
				strcat(dummy, "stat");
				temp2=fopen(dummy, "w");
				for(k=0; k<18; k++)
				{
					fprintf(temp2,"%d\n", 0);
				}
				fclose(temp2);
			}
		}
		fclose(temp1);
		
	}`*/



	

	srandom(time(NULL));
	for (i=0; i<2000; i++)	
	{
		r = random();
	
		r=r%1000;
		ran[i]=r;
	}

	

	srandom(time(NULL)+1);
	for (i=0; i<2000; i++)
	{
		ro = random();
	
		ro=ro%10000;
		runout[i]=ro;
	} 

	
	

	srandom(time(NULL)+2);
	for (i=0; i<2000; i++)
	{
		dis = random();
	
		dis=dis%1000;
		dismissal[i]=dis;
	}

	srandom(time(NULL) + 3);
	for (i=0; i<2000; i++)
	{
		r = random();
	
		r=r%1000;
		comm[i]=r;

	}
	fcomm=fopen("commentary.txt", "w");

	pitch=(float)(ran[0]/(1000.000))*(0.6)+0.7;
	printf("%f\n", pitch);
	//Toss:
	
	toss=ran[0]%2;
	tosschoose=ran[1]%2;
	if(toss==0)
	{
		printf("%s has won the toss and chosen to ", team1);
		fprintf(fcomm, "%s has won the toss and chosen to ", team1);
	}	
	else
	{
		printf("%s has won the toss and chosen to ", team2);
		fprintf(fcomm, "%s has won the toss and chosen to ", team2);
	}
	if(tosschoose==0)
	{printf("bat first.\n\n"); fprintf(fcomm, "bat first.\n\n"); }
	else
	{printf("field first.\n\n"); fprintf(fcomm, "field first.\n\n");} 
	if((toss+tosschoose)%2==1)
	{
		strcpy(dummy, team1);
		strcpy(team1, team2);
		strcpy(team2, dummy);


	}

	strcpy(bigbuffer, "Data/Teams/");
	strcat(bigbuffer, team1);
	strcat(bigbuffer, ".txt");

	t1=fopen(bigbuffer, "r");
	

	for(j=1; j<12; j++)
	{
		 fscanf(t1,"%s", team1p[j]);

	}

	

	strcpy(bigbuffer, "Data/Teams/");
	strcat(bigbuffer, team2);
	strcat(bigbuffer, ".txt");

	t2=fopen(bigbuffer, "r");
	//getchar();
	

	
	{printf("Which mode do you prefer?\n");
	printf("1. Automatic\n2. Manual\n");
	scanf("%d", &mode);
	getchar();}
	printf("\n\n\n");
	for(j=1; j<12; j++)
	{
		 fscanf(t2,"%s", team2p[j]);

	}
	m=2;
	bord=fopen("bowlorder", "r");
	bowlorder();
	
	t1runs=0;
	
	
	strcpy(btst, team1p[1]);
	strcpy(btrn, team1p[2]);
	
	printf("\n\n%s\n\n", team1);
	fprintf(fcomm, "\n\n%s\n\n", team1);
	
	for(j=0; j<50 ; j++)

	{
		oruns=0;
		fscanf(bord, "%d", &l); 
		strcpy(bw, team2pbowl[l]);
		strcpy(wklnm, team2plname[wkt2]);
		if(strcmp(bwtypet2[l],"ros")==0 || strcmp(bwtypet2[l],"rlb")==0 || strcmp(bwtypet2[l],"las")==0)
		bowltype=2;
		else
		bowltype=1;
		if(m==12)
		break; 
		for(k=1; k<7 ; k++)
		{	
			
			i=((j*6+k)*2)-1;
			
			do {fielder=((comm[i+1])%11)+1+beeta;
				beeta++;
				fielder=fielder%11 +1;
				}
			while(fielder==l || fielder==wkt2);
			
			strcpy(fieldlnm, team2plname[fielder]);
 
			
			
			runb=ballcall4();
			if(runb==-1 || runb==-2)
			{	
				printf("%d.%d  %c %s to %c %s : OUT.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				fprintf(fcomm,"%d.%d  %c %s to %c %s : OUT.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm); 				
			}
				
				
			
			
			else if(runb==0)
			{
				printf("%d.%d  %c %s to %c %s : No run, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : No run, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				if(bowltype==1)
				comm0p();
				else
				comm0s();
			}
			else if(runb==4)
			{
				printf("%d.%d  %c %s to %c %s : FOUR, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);	
				fprintf(fcomm, "%d.%d  %c %s to %c %s : FOUR, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);			four=1;	
				if(bowltype==1)
				comm4p();
				else
				comm4s();
								
			}
			else if(runb==6)
			{
				printf("%d.%d  %c %s to %c %s : SIX.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : SIX.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
	 			six=1;
			}
			else if(runb==1)
			{
				printf("%d.%d  %c %s to %c %s : 1 run, ", j, k, bowlfnm[0], bowllnm,batfnm[0],batlnm);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : 1 run, ", j, k, bowlfnm[0], bowllnm,batfnm[0],batlnm);
				if(bowltype==1)				
				comm1p();
				
				else
				comm1s();

			}	
			else if (runb==2)
			{
				printf("%d.%d  %c %s to %c %s : %d runs, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : %d runs, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
				comm2p();
			} 
			else if (runb==3)
			{
				printf("%d.%d  %c %s to %c %s : %d runs, \n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : %d runs.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
			} 		
		
			
				//usleep(600000);
			if(runb>=0)
			oruns=oruns+runb;
			
			
				
			for(n=1; n<12; n++)
			{
				if(strcmp(btst, team1p[n])==0)
				{	
					if(runb>=0)
					{
						team1pbatrun[n]=team1pbatrun[n]+runb;
						team1pball[n]=team1pball[n]+1;
						team1pfour[n]=team1pfour[n]+ four;
						team1psix[n]=team1psix[n]+ six;	
						break;
					}
					else if(runb<0)
					{
						team1pball[n]=team1pball[n]+1;
						break;


					}
		
				}
			}
				
			for(q=1; q<12; q++)
			{
				if(strcmp(btrn, team1p[q])==0)
				{
					strcpy(bigbuffer, "Data/Players/");
					strcat(bigbuffer, btrn);
					strcat(bigbuffer, ".txt");
					btrnf=fopen(bigbuffer, "r");
					fscanf(btrnf,"%s", btrnfnm);
					fscanf(btrnf,"%s", btrnlnm);
					fclose(btrnf);				
					break;	
				}
			}
				
			four=0;
			six=0;
				
							
			if(runb==-1)
			{
			
				printf("     ");
				fprintf(fcomm, "     ");
				for(r=1; r<12; r++)
				{
					if(strcmp(bw, team2p[r])==0)
					{
						team1dism[n][2]=r;						
						break;
					}
				
				}
				{
					strcpy(bigbuffer, "Data/Players/");
					strcat(bigbuffer, bw);
					strcat(bigbuffer, ".txt");

					distype=fopen(bigbuffer, "r");
					fscanf(distype,"%s", bufferd);
					fscanf(distype,"%s", bufferd);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%s", bufferd);
					fscanf(distype,"%s", bwtype);
					fclose(distype);				
				}
									
						
				if(strcmp(bwtype,"ros")==0 || strcmp(bwtype,"rlb")==0 || strcmp(bwtype,"las")==0)
				{
					if(dismissal[i]<648)
					{
						team1dism[n][0]=1;	
						fielder=((dismissal[i+1])%11)+1;
						if(fielder==r)
						fielder=wkt2;
						team1dism[n][1]=fielder;
						printf(" %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[fielder], team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
						fprintf(fcomm, " %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[fielder], team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
					}
					else if(dismissal[i]<848)
					{
						team1dism[n][0]=2;

						printf(" %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);
						fprintf(fcomm, " %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);
			
					}
					else if(dismissal[i]<970)
					{
						team1dism[n][0]=3;

						printf(" %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);
						fprintf(fcomm, " %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);

					}
				
					else if(dismissal[i]<998)
					{
						team1dism[n][0]=4;
						fielder=wkt2;
						team1dism[n][1]=fielder;

						printf(" %c %s st %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[fielder], team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
						fprintf(fcomm, " %c %s st %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[fielder], team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 

					}
					else if(dismissal[i]<1000)
					{
						team1dism[n][0]=5;
					
						printf(" %c %s hit wicket  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
						fprintf(fcomm, " %c %s hitwicket b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm,  team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
					
					}
				}
			////
				else	
				{	if(dismissal[i]<645)
					{
						team1dism[n][0]=1;	
						fielder=((dismissal[i+1])%11)+1;
						if(fielder==r)
						fielder=wkt2;
						team1dism[n][1]=fielder;
						printf(" %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[fielder], team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
						fprintf(fcomm, " %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[fielder], team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
					}
					else if(dismissal[i]<878)
					{
						team1dism[n][0]=2;

						printf(" %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);
						fprintf(fcomm, " %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);
			
					}
					else if(dismissal[i]<1000)
					{
						team1dism[n][0]=3;

						printf(" %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);
						fprintf(fcomm, " %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team2plname[r], team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100);

					}
				
				}
			
				w++;			
				m++;
				if(m==12)
				goto flag;
									
				strcpy(btst,team1p[m]);
				n=m;
			}

			if(runb==-2)
			{
				printf(" %c %s run out  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm,team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
				fprintf(fcomm," %c %s run out  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm,team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], (float)team1pbatrun[n]/(team1pball[n])*100); 
				team1dism[n][0]=6;
							
				m++;
				if(m==12)
				goto flag;
									
				strcpy(btst,team1p[m]);
				n=m;
			}

			
			
			if(runb>0 && (runb%2)!=0)
			{	
				strcpy(dummy,btst);
				strcpy(btst,btrn);
				strcpy(btrn,dummy);
					
											
			}
			getchar();
			
			
		
			
		}
		
		flag:

		if(k==7 && oruns==0)
		maiden=1;
		
		
	
		for(r=1; r<12; r++)
		{
			if(strcmp(bw, team2p[r])==0)
			{
				team2pbowlrun[r]=team2pbowlrun[r]+oruns;
				
				
				team2pwicket[r]=team2pwicket[r]+w;
				w=0;
				team2pmaiden[r]=team2pmaiden[r]+maiden;
				maiden=0;
				if(m==12 && k!=6)
				team2pcarryover[r]=team2pcarryover[r] + k;
				else
				team2pover[r]=team2pover[r]+1;	
				break;
					
						
			}
		}
				
		t1runs=t1runs+oruns;
		if(m==12)
		break;
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf("  End of over %d (%d runs)\t\t  %s   %d/%d (RR: %2.2f)\n", j+1, oruns, team1, t1runs, m-2, (float)t1runs/(j+1));
		fprintf(fcomm,"  End of over %d (%d runs)\t\t  %s  %d/%d (RR: %2.2f)\n", j+1, oruns, team1, t1runs, m-2, (float)t1runs/(j+1)); 
		if(runb>=0)
		{
			printf("  %c %s  %d*(%d b %dx4 %dx6) \t\t %c %s  %d*(%d b %dx4 %dx6)\n",batfnm[0],batlnm, team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], btrnfnm[0],btrnlnm,team1pbatrun[q],team1pball[q],team1pfour[q],team1psix[q]);
			fprintf(fcomm, "  %c %s  %d*(%d b %dx4 %dx6) \t\t %c %s  %d*(%d b %dx4 %dx6)\n",batfnm[0],batlnm, team1pbatrun[n], team1pball[n], team1pfour[n], team1psix[n], btrnfnm[0],btrnlnm,team1pbatrun[q],team1pball[q],team1pfour[q],team1psix[q]);
		}
		else
		{
			printf("  %c %s  %d*(%d b %dx4 %dx6)\n",btrnfnm[0], btrnlnm,team1pbatrun[q],team1pball[q],team1pfour[q],team1psix[q]);
			fprintf(fcomm, "  %c %s  %d*(%d b %dx4 %dx6)\n",btrnfnm[0], btrnlnm,team1pbatrun[q],team1pball[q],team1pfour[q],team1psix[q]);
		}
		printf("  %c %s     %d-%d-%d-%d\n",bowlfnm[0], bowllnm, team2pover[r],team2pmaiden[r],team2pbowlrun[r],team2pwicket[r]  );     
		fprintf(fcomm, "  %c %s     %d-%d-%d-%d\n",bowlfnm[0], bowllnm, team2pover[r],team2pmaiden[r],team2pbowlrun[r],team2pwicket[r]  );    
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		if(mode==2)
		getchar();
		if(mode==1){}
		//usleep(600000);
		
		{
			strcpy(dummy,btst);
			strcpy(btst,btrn);
			strcpy(btrn,dummy);
			
		}
		
		oruns=0;	

	}
	
	fclose(bord);
	
	oruns=0;
	counter=0;
	counter4=0;
	//getchar();

	printf("\n\n");
	fprintf(fcomm, "\n\n");
	printf("%-20s\t\t\t\t ", team1); printf("           R   B   4s  6s  SR\n");
	fprintf(fcomm, "%-20s\t\t\t\t ", team1); fprintf(fcomm, "           R   B   4s  6s  SR\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	for(d=1; d<m+1&& d<12; d++)
	{
		printf("%c %-15s ", team1pfname[d][0], team1plname[d]);
		fprintf(fcomm, "%c %-15s ", team1pfname[d][0], team1plname[d]);
		if(team1dism[d][0]==1)
		{
			printf(" c %-15s b %-15s    ", team2plname[team1dism[d][1]], team2plname[team1dism[d][2]]);
			fprintf(fcomm, " c %-15s b %-15s    ", team2plname[team1dism[d][1]], team2plname[team1dism[d][2]]);
		}			
		else if(team1dism[d][0]==2)
		{
			printf("   %-15s b %-15s    ", "",  team2plname[team1dism[d][2]]);
			fprintf(fcomm, "   %-15s b %-15s    ", "",  team2plname[team1dism[d][2]]);
		}
		else if(team1dism[d][0]==3)
		{	
			printf(" lbw%-15sb %-15s    ", "",team2plname[team1dism[d][2]]);
			fprintf(fcomm, " lbw%-15sb %-15s    ", "",team2plname[team1dism[d][2]]);
		}	
		else if(team1dism[d][0]==4)
		{
			printf(" st %-15sb %-15s    ",team2plname[team1dism[d][1]], team2plname[team1dism[d][2]]);
			fprintf(fcomm, " st %-15sb %-15s    ",team2plname[team1dism[d][1]], team2plname[team1dism[d][2]]);
		}			
		else if(team1dism[d][0]==5)
		{
			printf(" hit wicket %-6s b %-15s    ","", team2plname[team1dism[d][2]]);
			fprintf(fcomm, " hit wicket %-6s b %-15s    ","", team2plname[team1dism[d][2]]);
		}
		else if(team1dism[d][0]==6)
		{
			printf(" run out \t\t\t          ");
			fprintf(fcomm, " run out \t\t\t          ");
		}			
		else
		{
			printf(" not out \t\t\t          ");
			fprintf(fcomm, " not out \t\t\t          ");
		}	
		printf("%3d  %3d  %2d  %2d  ", team1pbatrun[d], team1pball[d], team1pfour[d], team1psix[d]);  			printf("%5.2f\n", (float)team1pbatrun[d]/(team1pball[d])*100);
		fprintf(fcomm, "%3d  %3d  %2d  %2d  ", team1pbatrun[d], team1pball[d], team1pfour[d], team1psix[d]);  			fprintf(fcomm, "%5.2f\n", (float)team1pbatrun[d]/(team1pball[d])*100);
	} 

	if(m==12)
	{	
		if(k!=6)
		{
			printf("\n\n\t %s  : %d in %d.%d overs\n\n",team1, t1runs, j, k);
			fprintf(fcomm, "\n\n\t %s  : %d in %d.%d overs\n\n",team1, t1runs, j, k);
		}
		else
		{
			printf("\n\n\t %s : %d in %d overs\n\n",team1, t1runs, j+1);
			fprintf(fcomm, "\n\n\t %s : %d in %d overs\n\n",team1, t1runs, j+1);
		}
	}
	else
	{
		printf("\n\n\t %s : %d/%d in 50 overs\n\n", team1, t1runs, m-2);
		fprintf(fcomm,"\n\n\t %s : %d/%d in 50 overs\n\n", team1, t1runs, m-2);
	} 
	//getchar();

	printf("\n\n");
	fprintf(fcomm, "\n\n");
	printf("Bowling\t\t\t\t\t\t"); printf("  O    M    R    W   Econ\n");
	fprintf(fcomm, "Bowling\t\t\t\t\t\t"); fprintf(fcomm, "  O    M    R    W   Econ\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	for(d=1; d<6; d++)
	{
		for(r=1; r<12; r++)
		{
			if(strcmp(team2pbowl[d],team2p[r])==0)
			break;
		}
		printf("%c %-20s\t\t\t\t", team2pfname[r][0], team2plname[r]);
		fprintf(fcomm, "%c %-20s\t\t\t\t", team2pfname[r][0], team2plname[r]);
		if(m==12 && team2pcarryover[r]!=0)
		{printf("%3d.%d %2d   %2d   %2d", team2pover[r], team2pcarryover[r], team2pmaiden[r], team2pbowlrun[r], team2pwicket[r]);
		fprintf(fcomm, "%3d.%d %2d   %2d   %2d", team2pover[r], team2pcarryover[r], team2pmaiden[r], team2pbowlrun[r], team2pwicket[r]);}
		else
		{printf("%3d   %2d   %2d   %2d", team2pover[r], team2pmaiden[r], team2pbowlrun[r], team2pwicket[r]);
		fprintf(fcomm, "%3d   %2d   %2d   %2d", team2pover[r], team2pmaiden[r], team2pbowlrun[r], team2pwicket[r]);
		}
		printf("   %2.2f\n", (float)team2pbowlrun[r]/((float)(team2pover[r])+((float)team2pcarryover[r]/6)));
		fprintf(fcomm, "   %2.2f\n", (float)team2pbowlrun[r]/((float)(team2pover[r])+((float)team2pcarryover[r]/6)));
		
	} 
	t1finw=m-2;

	//getchar();
		
	////////////////////////////////////////////////////////////////////

	
	m=2;	
	w=0;
	bord=fopen("bowlorder", "r");
	
	

	t2runs=0;
	
	
	strcpy(btst, team2p[1]);
	strcpy(btrn, team2p[2]);
	
	printf("\n\n%s  (Target : %d in 50 overs)\n\n", team2, t1runs+1);
	fprintf(fcomm, "\n\n%s  (Target : %d in 50 overs)\n\n", team2, t1runs+1);
	for(j=0; j<50 ; j++)

	{
		oruns=0;
		fscanf(bord, "%d", &l); 
		strcpy(bw, team1pbowl[l]);
		strcpy(wklnm, team1plname[wkt1]);
		if(strcmp(bwtypet1[l],"ros")==0 || strcmp(bwtypet1[l],"rlb")==0 || strcmp(bwtypet1[l],"las")==0)
		bowltype=2;
		else
		bowltype=1;
		if(m==12)
		break; 
		for(k=1; k<7 ; k++)
		{	
			
			i=600+((j*6+k)*2)-1;
			do 
			{fielder=((comm[i+1])%11)+1+ beeta;
				beeta++;
				fielder=fielder%11 +1; 
			}
			while (fielder==l || fielder==wkt1) ;
			
			strcpy(fieldlnm, team1plname[fielder]);
			runb=ballcall3();
			if(runb==-1 || runb==-2)
			{	
				printf("%d.%d  %c %s to %c %s : OUT.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				fprintf(fcomm,"%d.%d  %c %s to %c %s : OUT.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm); 				
			}	
				
			
			
				
				
			
			
			else if(runb==0)
			{
				printf("%d.%d  %c %s to %c %s : No run, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : No run, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				if(bowltype==1)				
				comm0p();
				
				else
				comm0s();
			}
			else if(runb==4)
			{
				printf("%d.%d  %c %s to %c %s : FOUR, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);	
				fprintf(fcomm, "%d.%d  %c %s to %c %s : FOUR, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);			four=1;	

				if(bowltype==1)
				comm4p();
				else
				comm4s();				
			}
			else if(runb==6)
			{
				printf("%d.%d  %c %s to %c %s : SIX.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : SIX.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm);
	 			six=1;
			}
			else if(runb==1)
			{
				printf("%d.%d  %c %s to %c %s : 1 run, ", j, k, bowlfnm[0], bowllnm,batfnm[0],batlnm);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : 1 run, ", j, k, bowlfnm[0], bowllnm,batfnm[0],batlnm);
				if(bowltype==1)				
				comm1p();
				
				else
				comm1s();

			}	
			else if (runb==2)
			{
				printf("%d.%d  %c %s to %c %s : %d runs, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : %d runs, ", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
				if(bowltype==1)
				comm2p();
				else 
				{
					printf(" \n");
					fprintf(fcomm, " \n");
				}
				
			} 
			else if (runb==3)
			{
				printf("%d.%d  %c %s to %c %s : %d runs, \n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
				fprintf(fcomm, "%d.%d  %c %s to %c %s : %d runs.\n", j, k, bowlfnm[0], bowllnm, batfnm[0], batlnm, runb);
			} 		
		
		
			
				//usleep(600000);
			if(runb>=0)
			{
				oruns=oruns+runb;
				t2runs=t2runs+runb;
			}
			
				
			for(n=1; n<12; n++)
			{
				if(strcmp(btst, team2p[n])==0)
				{	
					if(runb>=0)
					{
						team2pbatrun[n]=team2pbatrun[n]+runb;
						team2pball[n]=team2pball[n]+1;
						team2pfour[n]=team2pfour[n]+ four;
						team2psix[n]=team2psix[n]+ six;	
						break;
					}
					else if(runb<0)
					{
						team2pball[n]=team2pball[n]+1;
						break;


					}
		
				}
			}
				
			for(q=1; q<12; q++)
			{
				if(strcmp(btrn, team2p[q])==0)
				{
					strcpy(bigbuffer, "Data/Players/");
					strcat(bigbuffer, btrn);
					strcat(bigbuffer, ".txt");

					btrnf=fopen(bigbuffer, "r");
					fscanf(btrnf,"%s", btrnfnm);
					fscanf(btrnf,"%s", btrnlnm);
					fclose(btrnf);	
						break;	
				}
			}	
				four=0;
				six=0;
				
							
			if(runb==-1)
			{
			
				printf("     ");
				fprintf(fcomm, "     ");
				for(r=1; r<12; r++)
				{
					if(strcmp(bw, team1p[r])==0)
					{
						team2dism[n][2]=r;						
						break;
					}
				
				}
				{

					strcpy(bigbuffer, "Data/Players/");
					strcat(bigbuffer, bw);
					strcat(bigbuffer, ".txt");
					distype=fopen(bigbuffer, "r");
					fscanf(distype,"%s", bufferd);
					fscanf(distype,"%s", bufferd);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%f", &buffer1d);
					fscanf(distype,"%s", bufferd);
					fscanf(distype,"%s", bwtype);
					fclose(distype);				
				}
									
						
				if(strcmp(bwtype,"ros")==0 || strcmp(bwtype,"rlb")==0 || strcmp(bwtype,"las")==0)
				{
					if(dismissal[i]<648)
					{
						team2dism[n][0]=1;	
						fielder=((dismissal[i+1])%11)+1;
						if(fielder==r)
						fielder=wkt1;
						team2dism[n][1]=fielder;
						printf(" %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[fielder], team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
						fprintf(fcomm, " %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[fielder], team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
					}
					else if(dismissal[i]<848)
					{
						team2dism[n][0]=2;

						printf(" %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);
						fprintf(fcomm, " %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);
			
					}
					else if(dismissal[i]<970)
					{
						team2dism[n][0]=3;

						printf(" %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);
						fprintf(fcomm, " %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);

					}
				
					else if(dismissal[i]<998)
					{
						team2dism[n][0]=4;
						fielder=wkt1;
						team2dism[n][1]=fielder;

						printf(" %c %s st %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[fielder], team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
						fprintf(fcomm, " %c %s st %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[fielder], team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 

					}
					else if(dismissal[i]<1000)
					{
						team2dism[n][0]=5;
					
						printf(" %c %s hit wicket  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
						fprintf(fcomm, " %c %s hitwicket b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm,  team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
					
					}
				}
			////
				else	
				{	if(dismissal[i]<645)
					{
						team2dism[n][0]=1;	
						fielder=((dismissal[i+1])%11)+1;
						if(fielder==r)
						fielder=wkt1;
						team2dism[n][1]=fielder;
						printf(" %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[fielder], team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
						fprintf(fcomm, " %c %s c %s b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[fielder], team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
					}
					else if(dismissal[i]<878)
					{
						team2dism[n][0]=2;

						printf(" %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);
						fprintf(fcomm, " %c %s  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);
			
					}
					else if(dismissal[i]<1000)
					{
						team2dism[n][0]=3;

						printf(" %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);
						fprintf(fcomm, " %c %s lbw  b %s  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm, team1plname[r], team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100);

					}
				
				}
			
				w++;			
				m++;
				if(m==12)
				goto flag2;
									
				strcpy(btst,team2p[m]);
				n=m;
			}
		
			if(runb==-2)
			{
				printf(" %c %s run out  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm,team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
				fprintf(fcomm," %c %s run out  %d(%d b %dx4 %dx6) SR - %3.2f\n", batfnm[0], batlnm,team1pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], (float)team2pbatrun[n]/(team2pball[n])*100); 
				team2dism[n][0]=6;
							
				m++;
				if(m==12)
				goto flag2;
									
				strcpy(btst,team2p[m]);
				n=m;
			}
			
			
			if(runb>0 && (runb%2)!=0)
			{	
				strcpy(dummy,btst);
				strcpy(btst,btrn);
				strcpy(btrn,dummy);
					
											
			}
			if(t2runs>t1runs)
			{
				victory=2;
				break;
			
			}
			
			getchar();
			
		
			
		}
		
		

		flag2:

		if(k==7 && oruns==0)
		maiden=1;
		
		
	
		for(r=1; r<12; r++)
		{
			if(strcmp(bw, team1p[r])==0)
			{
				team1pbowlrun[r]=team1pbowlrun[r]+oruns;
				
				
				team1pwicket[r]=team1pwicket[r]+w;
				w=0;
				team1pmaiden[r]=team1pmaiden[r]+maiden;
				maiden=0;
				if(m==12 && k!=6)
				team1pcarryover[r]=team1pcarryover[r] + k;
				else if(victory==2 & k!=6)
				team1pcarryover[r]=team1pcarryover[r] + k;
				else
				team1pover[r]=team1pover[r]+1;	
				break;
					
						
			}
		}
	
				
				
			
		
		if(m==12 || victory==2)
		break;
		
		
		
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf("  End of over %d (%d runs)  %s  %d/%d (%d runs required from %d overs, RR: %2.2f, RRR: %2.2f)\n", j+1, oruns, team2, t2runs, m-2, t1runs-t2runs+1, 50-(j+1), (float)t2runs/(j+1), (float)(t1runs-t2runs+1)/(49-j));
		fprintf(fcomm, "  End of over %d (%d runs)  %s  %d/%d (%d runs required from %d overs, RR: %2.2f, RRR: %2.2f)\n", j+1, oruns, team2, t2runs, m-2, t1runs-t2runs+1, 50-(j+1), (float)t2runs/(j+1), (float)(t1runs-t2runs+1)/(49-j));
		if(runb>=0)
		{
			printf("  %c %s  %d*(%d b %dx4 %dx6) \t\t %c %s  %d*(%d b %dx4 %dx6)\n",batfnm[0],batlnm, team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], btrnfnm[0],btrnlnm,team2pbatrun[q],team2pball[q],team2pfour[q],team2psix[q]);
			fprintf(fcomm, "  %c %s  %d*(%d b %dx4 %dx6) \t\t %c %s  %d*(%d b %dx4 %dx6)\n",batfnm[0],batlnm, team2pbatrun[n], team2pball[n], team2pfour[n], team2psix[n], btrnfnm[0],btrnlnm,team2pbatrun[q],team2pball[q],team2pfour[q],team2psix[q]);
		}	
		else
		{
			printf("  %c %s  %d*(%d b %dx4 %dx6)\n",btrnfnm[0], btrnlnm,team2pbatrun[q],team2pball[q],team2pfour[q],team2psix[q]);
			fprintf(fcomm, "  %c %s  %d*(%d b %dx4 %dx6)\n",btrnfnm[0], btrnlnm,team2pbatrun[q],team2pball[q],team2pfour[q],team2psix[q]);
		}	
		printf("  %c %s     %d-%d-%d-%d\n",bowlfnm[0], bowllnm, team1pover[r],team1pmaiden[r],team1pbowlrun[r],team1pwicket[r]  ); 
		fprintf(fcomm, "  %c %s     %d-%d-%d-%d\n",bowlfnm[0], bowllnm, team1pover[r],team1pmaiden[r],team1pbowlrun[r],team1pwicket[r]  );       
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		if(mode==2)
		getchar();
		if(mode==1){}
		//usleep(600000);
		
		{
			strcpy(dummy,btst);
			strcpy(btst,btrn);
			strcpy(btrn,dummy);
			
		}
		

	}
	
	fclose(bord);
	printf("\n\n");
	fprintf(fcomm,"\n\n");
	printf("%-20s\t\t\t\t ", team2); printf("           R   B   4s  6s  SR\n");
	fprintf(fcomm,"%-20s\t\t\t\t ", team2); fprintf(fcomm, "           R   B   4s  6s  SR\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	for(d=1; d<m+1&& d<12; d++)
	{
		printf("%c %-15s ", team2pfname[d][0], team2plname[d]);
		fprintf(fcomm,"%c %-15s ", team2pfname[d][0], team2plname[d]);
		
		if(team2dism[d][0]==1)
		{
			printf(" c %-15s b %-15s    ", team1plname[team2dism[d][1]], team1plname[team2dism[d][2]]);
			fprintf(fcomm," c %-15s b %-15s    ", team1plname[team2dism[d][1]], team1plname[team2dism[d][2]]);
		}	
		else if(team2dism[d][0]==2)
		{
			printf("   %-15s b %-15s    ","", team1plname[team2dism[d][2]]);
			fprintf(fcomm, "   %-15s b %-15s    ","", team1plname[team2dism[d][2]]);
		}

		else if(team2dism[d][0]==3)
		{
			printf(" lbw%-15sb %-15s    ","",  team1plname[team2dism[d][2]]);
			fprintf(fcomm, " lbw%-15sb %-15s    ","",  team1plname[team2dism[d][2]]);
		}
		else if(team2dism[d][0]==4)
		{
			printf(" st %-15sb %-15s    ",team1plname[team2dism[d][1]], team1plname[team2dism[d][2]]);
			fprintf(fcomm, " st %-15sb %-15s    ",team1plname[team2dism[d][1]], team1plname[team2dism[d][2]]);
		}
		else if(team2dism[d][0]==5)
		{
			printf(" hit wicket %-6s b %-15s    ", "",  team1plname[team2dism[d][2]]);
			fprintf(fcomm, " hit wicket %-6s b %-15s    ", "",  team1plname[team2dism[d][2]]);
		}

		else if(team2dism[d][0]==6)
		{
			printf(" run out \t\t\t          ");
			fprintf(fcomm, " run out \t\t\t          ");
		}	
		else
		{
			printf(" not out \t\t\t          ");
			fprintf(fcomm, " not out \t\t\t          ");
		}
		printf("%3d  %3d  %2d  %2d  ", team2pbatrun[d], team2pball[d], team2pfour[d], team2psix[d]);  			printf("%5.2f\n", (float)team2pbatrun[d]/(team2pball[d])*100);
		fprintf(fcomm, "%3d  %3d  %2d  %2d  ", team2pbatrun[d], team2pball[d], team2pfour[d], team2psix[d]);  			fprintf(fcomm, "%5.2f\n", (float)team2pbatrun[d]/(team2pball[d])*100);

	} 

	//getchar();

	printf("\n\n");
	printf("Bowling\t\t\t\t\t\t"); printf("  O    M    R    W   Econ\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	fprintf(fcomm, "\n\n");
	fprintf(fcomm, "Bowling\t\t\t\t\t\t"); fprintf(fcomm, "  O    M    R    W   Econ\n");
	fprintf(fcomm, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

	for(d=1; d<6; d++)
	{
		for(r=1; r<12; r++)
		{
			if(strcmp(team1pbowl[d],team1p[r])==0)
			break;
		}
		printf("%c %-20s\t\t\t\t", team1pfname[r][0], team1plname[r]);
		fprintf(fcomm, "%c %-20s\t\t\t\t", team1pfname[r][0], team1plname[r]);
		if(m==12 && team1pcarryover[r]!=0)
		{
			printf("%3d.%d %2d   %2d   %2d", team1pover[r], team1pcarryover[r], team1pmaiden[r], team1pbowlrun[r], team1pwicket[r]);
			fprintf(fcomm, "%3d.%d %2d   %2d   %2d", team1pover[r], team1pcarryover[r], team1pmaiden[r], team1pbowlrun[r], team1pwicket[r]);
		}
		else if(victory==2 && team1pcarryover[r]!=0)
		{
			printf("%3d.%d %2d   %2d   %2d", team1pover[r], team1pcarryover[r], team1pmaiden[r], team1pbowlrun[r], team1pwicket[r]);
			fprintf(fcomm, "%3d.%d %2d   %2d   %2d", team1pover[r], team1pcarryover[r], team1pmaiden[r], team1pbowlrun[r], team1pwicket[r]);
		}
		else
		{
			printf("%3d   %2d   %2d   %2d", team1pover[r], team1pmaiden[r], team1pbowlrun[r], team1pwicket[r]);  
			fprintf(fcomm, "%3d   %2d   %2d   %2d", team1pover[r], team1pmaiden[r], team1pbowlrun[r], team1pwicket[r]);  
		}
		printf("   %2.2f\n", (float)team1pbowlrun[r]/((float)(team1pover[r])+((float)team1pcarryover[r]/6)));
		fprintf(fcomm, "   %2.2f\n", (float)team1pbowlrun[r]/((float)(team1pover[r])+((float)team1pcarryover[r]/6)));
		
	} 

	//getchar();
	
	if(victory==2)
	{	if(k!=6)
		{
	
			printf("\n\n\t %s : %d/%d in %d.%d overs\n\n",team2, t2runs, m-2, j, k);
			fprintf(fcomm, "\n\n\t %s : %d/%d in %d.%d overs\n\n",team2, t2runs, m-2, j, k);	
		}
		else
		{
			printf("\n\n\t %s : %d/%d in %d overs\n\n",team2, t2runs, m-2, j+1);
			fprintf(fcomm, "\n\n\t %s : %d/%d in %d overs\n\n",team2, t2runs, m-2, j+1);
		}
	}	
	else if(m==12)
	{
		if(k!=6)
		{			
			printf("\n\n\t %s : %d in %d.%d overs\n\n",team2, t2runs, j, k);
			fprintf(fcomm, "\n\n\t %s : %d in %d.%d overs\n\n",team2, t2runs, j, k);
		}

		else
		{
			printf("\n\n\t %s : %d in %d overs\n\n",team2, t2runs, j+1);
			fprintf(fcomm, "\n\n\t %s : %d in %d overs\n\n",team2, t2runs, j+1);
		}
	}	
	else
	{
		printf("\n\n\t %s : %d/%d in 50 overs\n\n", team2, t2runs, m-2);
		fprintf(fcomm, "\n\n\t %s : %d/%d in 50 overs\n\n", team2, t2runs, m-2);
	}	
	if(victory==2)
	{
		printf("%s won the match by %d wickets.\n", team2, 12-m);
		fprintf(fcomm, "%s won the match by %d wickets.\n", team2, 12-m);
	}

	else if(t1runs==t2runs)
	{
		printf("Match tied.\n");
		fprintf(fcomm, "Match tied.\n");
		victory=3;
	}			
	else 
	{
		printf("%s won the match by %d runs.\n", team1, t1runs-t2runs);
		fprintf(fcomm, "%s won the match by %d runs.\n", team1, t1runs-t2runs);
	}
	
	////STATS////////
	for(i=1; i<12; i++)
	{
		strcpy(dummy, team1p[i]);
		
		FILE *stat;
		strcpy(bigbuffer, "Data/Stats/");
		strcat(bigbuffer, dummy);
		strcat(bigbuffer, "stat.txt");
		stat=fopen(bigbuffer, "r");
		fscanf(stat, "%d", &stmatches);
		stmatches++;
		fscanf(stat, "%d", &stbatinnings);
		if(team1pball[i]>0)
		stbatinnings++;
		fscanf(stat,"%d", &stbatnouts);
		if(team1dism[i][0]==0 && team1pball[i]>0)
		stbatnouts++;
		fscanf(stat, "%d", &stbatruns);
		stbatruns=stbatruns + team1pbatrun[i];
		fscanf(stat, "%d", &stbatballs);
		stbatballs=stbatballs + team1pball[i];
		fscanf(stat, "%d", &stbatbest);
		if(team1pbatrun[i]>stbatbest)
		stbatbest=team1pbatrun[i];
		fscanf(stat, "%d", &stbatfours);
		stbatfours=stbatfours + team1pfour[i];
		fscanf(stat, "%d", &stbatsixes);
		stbatsixes=stbatsixes + team1psix[i];
		fscanf(stat, "%d", &st50s);
		if(team1pbatrun[i]>=50 && team1pbatrun[i]<100)
		st50s++;		
		fscanf(stat, "%d", &st100s);
		if(team1pbatrun[i]>=100)
		st100s++;
		fscanf(stat, "%d", &stbowlinnings);
		if(team1pover[i]>0 || team1pcarryover[i]>0)
		stbowlinnings++;
		fscanf(stat, "%d", &stbowlballs);
		stbowlballs=stbowlballs + team1pover[i]*6 + team1pcarryover[i];
		fscanf(stat, "%d", &stbowlruns);
		stbowlruns=stbowlruns + team1pbowlrun[i];
		fscanf(stat, "%d", &stbowlwickets);
		stbowlwickets=stbowlwickets + team1pwicket[i];
		fscanf(stat, "%d", &st4wkts);
		if(team1pwicket[i]==4)
		st4wkts++;
		fscanf(stat, "%d", &st5wkts);
		if(team1pwicket[i]>=5)
		st5wkts++;
		fscanf(stat, "%d", &stbowlbestw);
		fscanf(stat, "%d", &stbowlbestr);
		if(team1pwicket[i]>stbowlbestw)
		{
			stbowlbestw=team1pwicket[i];
			stbowlbestr=team1pbowlrun[i];
		}
		else if(team1pwicket[i]==stbowlbestw && stbowlbestr>team1pbowlrun[i])
		{
			stbowlbestw=team1pwicket[i];
			stbowlbestr=team1pbowlrun[i];

		} 
		fclose(stat);
		strcpy(bigbuffer, "Data/Stats/");
		strcat(bigbuffer, dummy);
		strcat(bigbuffer, "stat.txt");
		stat=fopen(bigbuffer, "w");
		fprintf(stat, "%d\n", stmatches);
		fprintf(stat, "%d\n", stbatinnings);		
		fprintf(stat,"%d\n", stbatnouts);
		fprintf(stat, "%d\n", stbatruns);
		fprintf(stat, "%d\n", stbatballs);
		fprintf(stat, "%d\n", stbatbest);
		fprintf(stat, "%d\n", stbatfours);
		fprintf(stat, "%d\n", stbatsixes);
		fprintf(stat, "%d\n", st50s);
		fprintf(stat, "%d\n", st100s);
		fprintf(stat, "%d\n", stbowlinnings);
		fprintf(stat, "%d\n", stbowlballs);
		fprintf(stat, "%d\n", stbowlruns);
		fprintf(stat, "%d\n", stbowlwickets);
		fprintf(stat, "%d\n", st4wkts);
		fprintf(stat, "%d\n", st5wkts);
		fprintf(stat, "%d\n", stbowlbestw);
		fprintf(stat, "%d\n", stbowlbestr);

		fclose(stat);
	}

	for(i=1; i<12; i++)
	{
		strcpy(dummy, team2p[i]);
		
		FILE *stat;
		strcpy(bigbuffer, "Data/Stats/");
		strcat(bigbuffer, dummy);
		strcat(bigbuffer, "stat.txt");
		stat=fopen(bigbuffer, "r");
		fscanf(stat, "%d", &stmatches);
		stmatches++;
		fscanf(stat, "%d", &stbatinnings);
		if(team2pball[i]>0)
		stbatinnings++;
		fscanf(stat,"%d", &stbatnouts);
		if(team2dism[i][0]==0 && team2pball[i]>0)
		stbatnouts++;
		fscanf(stat, "%d", &stbatruns);
		stbatruns=stbatruns + team2pbatrun[i];
		fscanf(stat, "%d", &stbatballs);
		stbatballs=stbatballs + team2pball[i];
		fscanf(stat, "%d", &stbatbest);
		if(team2pbatrun[i]>stbatbest)
		stbatbest=team2pbatrun[i];
		fscanf(stat, "%d", &stbatfours);
		stbatfours=stbatfours + team2pfour[i];
		fscanf(stat, "%d", &stbatsixes);
		stbatsixes=stbatsixes + team2psix[i];
		fscanf(stat, "%d", &st50s);
		if(team2pbatrun[i]>=50 && team2pbatrun[i]<100)
		st50s++;		
		fscanf(stat, "%d", &st100s);
		if(team2pbatrun[i]>=100)
		st100s++;
		fscanf(stat, "%d", &stbowlinnings);
		if(team2pover[i]>0 || team2pcarryover[i]>0)
		stbowlinnings++;
		fscanf(stat, "%d", &stbowlballs);
		stbowlballs=stbowlballs + team2pover[i]*6 + team2pcarryover[i];
		fscanf(stat, "%d", &stbowlruns);
		stbowlruns=stbowlruns + team2pbowlrun[i];
		fscanf(stat, "%d", &stbowlwickets);
		stbowlwickets=stbowlwickets + team2pwicket[i];
		fscanf(stat, "%d", &st4wkts);
		if(team2pwicket[i]==4)
		st4wkts++;
		fscanf(stat, "%d", &st5wkts);
		if(team2pwicket[i]>=5)
		st5wkts++;
		fscanf(stat, "%d", &stbowlbestw);
		fscanf(stat, "%d", &stbowlbestr);
		if(team2pwicket[i]>stbowlbestw)
		{
			stbowlbestw=team2pwicket[i];
			stbowlbestr=team2pbowlrun[i];
		}
		else if(team2pwicket[i]==stbowlbestw && stbowlbestr>team2pbowlrun[i])
		{
			stbowlbestw=team2pwicket[i];
			stbowlbestr=team2pbowlrun[i];

		} 
		fclose(stat);
		strcpy(bigbuffer, "Data/Stats/");
		strcat(bigbuffer, dummy);
		strcat(bigbuffer, "stat.txt");
		stat=fopen(bigbuffer, "w");
		fprintf(stat, "%d\n", stmatches);
		fprintf(stat, "%d\n", stbatinnings);		
		fprintf(stat,"%d\n", stbatnouts);
		fprintf(stat, "%d\n", stbatruns);
		fprintf(stat, "%d\n", stbatballs);
		fprintf(stat, "%d\n", stbatbest);
		fprintf(stat, "%d\n", stbatfours);
		fprintf(stat, "%d\n", stbatsixes);
		fprintf(stat, "%d\n", st50s);
		fprintf(stat, "%d\n", st100s);
		fprintf(stat, "%d\n", stbowlinnings);
		fprintf(stat, "%d\n", stbowlballs);
		fprintf(stat, "%d\n", stbowlruns);
		fprintf(stat, "%d\n", stbowlwickets);
		fprintf(stat, "%d\n", st4wkts);
		fprintf(stat, "%d\n", st5wkts);
		fprintf(stat, "%d\n", stbowlbestw);
		fprintf(stat, "%d\n", stbowlbestr);
		fclose(stat);
			
	}
	fclose(fcomm);
	fclose(t1);
	fclose(t2);



	
	 		
	return(0);

}

int ballcall(void)
{
	FILE *bat;
	FILE *bowl;
	char bigbuffer2[100];
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, btst);
	strcat(bigbuffer2, ".txt");
	bat=fopen(bigbuffer2, "r");
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, bw);
	strcat(bigbuffer2, ".txt");
	bowl=fopen(bigbuffer2, "r");
	
	fscanf(bat,"%s", batfnm);
	fscanf(bat,"%s", batlnm);
	fscanf(bat,"%f", &btav1);
	fscanf(bat,"%f", &btsr1);
	fscanf(bat,"%f", &bwav1);
	fscanf(bat,"%f", &bwsr1);

	fscanf(bowl,"%s", bowlfnm);
	fscanf(bowl,"%s", bowllnm);
	fscanf(bowl,"%f", &btav2);
	fscanf(bowl,"%f", &btsr2);
	fscanf(bowl,"%f", &bwav2);
	fscanf(bowl,"%f", &bwsr2);

	

	out1= 100*(btav1/btsr1);
	
	sr2=(bwav2/bwsr2)*100;
	
	out=((out1*bwsr2)/34.71)*pitch; //This is the factor to decide if batsman survives or not. More factors can be added on later.

	sr=(btsr1*sr2)/80.67; // This is for scoring rate. More factors can be applied here too.

	r0=((-0.3651*sr) + 81.513)*10; // Took data of 3 random matches. Used linear regression to find these values. 
					// Will continue it further later. Values can be changed easily. 

	r1=((0.1356*sr) + 22.701)*10;

	r2=((0.0873*sr) - 0.8742)*10;

	r4=((0.0922*sr) - 1.3612)*10;		

	r6=((0.0426*sr) - 1.9615)*10;

		if (runout[i]<25)
		runb=-2;
		else if(ran[i+1]<(1000/out))
		runb=-1;
		else if (ran[i]<(r0))
		runb=0; 
		else if (ran[i]<(r0+r1))
		runb=1;
		else if (ran[i]<(r0+r1+r2))
		runb=2;
		else if (ran[i]<(r0+r1+r2+r4))
		runb=4;
		else if (ran[i]<(r0+r1+r2+r4+r6))				
		runb=6;
		else
		runb=3;

	fclose(bat);
	fclose(bowl);
	
	
	return(runb);

}

int ballcall4(void)
{
	FILE *bat;
	FILE *bowl;
	FILE *diff;

	float reqrate, agg, res;
	
	

	char bigbuffer2[100];
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, btst);
	strcat(bigbuffer2, ".txt");
	bat=fopen(bigbuffer2, "r");
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, bw);
	strcat(bigbuffer2, ".txt");
	bowl=fopen(bigbuffer2, "r");
	
	fscanf(bat,"%s", batfnm);
	fscanf(bat,"%s", batlnm);
	fscanf(bat,"%f", &btav1);
	fscanf(bat,"%f", &btsr1);
	fscanf(bat,"%f", &bwav1);
	fscanf(bat,"%f", &bwsr1);

	fscanf(bowl,"%s", bowlfnm);
	fscanf(bowl,"%s", bowllnm);
	fscanf(bowl,"%f", &btav2);
	fscanf(bowl,"%f", &btsr2);
	fscanf(bowl,"%f", &bwav2);
	fscanf(bowl,"%f", &bwsr2);

	
	
	

	diff=fopen("dldiff.txt", "r");

	fseek(diff, 61*(j)+6*(m-2), SEEK_SET);
	
	fscanf(diff," %f", &res);
	
	if(res<=4.70)
	{
		agg= 1 + ((1.4-1)/(4.70))*(4.70-res);
	
	}
	
	if(res>4.70)
	{
		agg= 1 - ((1-0.6)/(9.40))*(res-4.70);
	}

	//printf("%f\n", agg);
	
	btsr1=btsr1*agg;

	btav1=btav1/(sqrt(agg));

	out1= 100*(btav1/btsr1);
	
	sr2=(bwav2/bwsr2)*100;
	
	out=((out1*bwsr2)/34.71)*pitch*1.2; //34.71; //This is the factor to decide if batsman survives or not. More factors can be added on later.

	sr=(btsr1*sr2)/80.67; // This is for scoring rate. More factors can be applied here too.

	r0=((-0.3651*sr) + 81.513)*10; // Took data of 3 random matches. Used linear regression to find these values. 
					// Will continue it further later. Values can be changed easily. 

	r1=((0.1356*sr) + 22.701)*10;

	r2=((0.0873*sr) - 0.8742)*10;

	r4=((0.0922*sr) - 1.3612)*10;		

	r6=((0.0426*sr) - 1.9615)*10;

		if (runout[i]<25)
		runb=-2;
		else if(ran[i+1]<(1000/out))
		runb=-1;
		else if (ran[i]<(r0))
		runb=0; 
		else if (ran[i]<(r0+r1))
		runb=1;
		else if (ran[i]<(r0+r1+r2))
		runb=2;
		else if (ran[i]<(r0+r1+r2+r4))
		runb=4;
		else if (ran[i]<(r0+r1+r2+r4+r6))				
		runb=6;
		else
		runb=3;
	fclose(diff);
	fclose(bat);
	fclose(bowl);
	

	return(runb);

}

int ballcall3(void)
{
	FILE *bat;
	FILE *bowl;
	FILE *diff;

	float reqrate, agg, res;
	
	
	char bigbuffer2[100];
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, btst);
	strcat(bigbuffer2, ".txt");
	bat=fopen(bigbuffer2, "r");
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, bw);
	strcat(bigbuffer2, ".txt");
	bowl=fopen(bigbuffer2, "r");
	
	fscanf(bat,"%s", batfnm);
	fscanf(bat,"%s", batlnm);
	fscanf(bat,"%f", &btav1);
	fscanf(bat,"%f", &btsr1);
	fscanf(bat,"%f", &bwav1);
	fscanf(bat,"%f", &bwsr1);

	fscanf(bowl,"%s", bowlfnm);
	fscanf(bowl,"%s", bowllnm);
	fscanf(bowl,"%f", &btav2);
	fscanf(bowl,"%f", &btsr2);
	fscanf(bowl,"%f", &bwav2);
	fscanf(bowl,"%f", &bwsr2);

	reqrate=(float)(t1runs+1-t2runs)/(((50-j)*6)-k+1);
	
	agg=(reqrate*100)/btsr1;

	diff=fopen("dldiff.txt", "r");

	fseek(diff, 61*(j)+6*(m-2), SEEK_SET);
	
	fscanf(diff," %f", &res);
	
	if(agg>1)
	{
		agg= 1 + ((agg-1)/(11.10))*(14.10-res);
	
	}
	
	if(agg<=1)
	{
		agg= agg + ((1-agg)/(11.10))*(14.10-res);
	}

	////printf("%f\n", agg);
	
	btsr1=btsr1*agg;

	btav1=btav1/(sqrt(agg));

	out1= 100*(btav1/btsr1);
	
	sr2=(bwav2/bwsr2)*100;
	
	out=((out1*bwsr2)/34.71)*pitch; //34.71; //This is the factor to decide if batsman survives or not. More factors can be added on later.

	sr=(btsr1*sr2)/80.67; // This is for scoring rate. More factors can be applied here too.

	r0=((-0.3651*sr) + 81.513)*10; // Took data of 3 random matches. Used linear regression to find these values. 
					// Will continue it further later. Values can be changed easily. 

	r1=((0.1356*sr) + 22.701)*10;

	r2=((0.0873*sr) - 0.8742)*10;

	r4=((0.0922*sr) - 1.3612)*10;		

	r6=((0.0426*sr) - 1.9615)*10;

		if (runout[i]<25)
		runb=-2;
		else if(ran[i+1]<(1000/out))
		runb=-1;
		else if (ran[i]<(r0))
		runb=0; 
		else if (ran[i]<(r0+r1))
		runb=1;
		else if (ran[i]<(r0+r1+r2))
		runb=2;
		else if (ran[i]<(r0+r1+r2+r4))
		runb=4;
		else if (ran[i]<(r0+r1+r2+r4+r6))				
		runb=6;
		else
		runb=3;

	fclose(diff);
	fclose(bat);
	fclose(bowl);
	
	
	return(runb);

}

int ballcall2(void)
{
	FILE *bat;
	FILE *bowl;
	FILE *dl;

	float resrem, resover, reswicket, e1, e2, reqrate, c, batqual, gamma;
	float p1, p2, p3, p4, p6, pw, p0;
	int s;
	
	char bigbuffer2[100];
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, btst);
	strcat(bigbuffer2, ".txt");
	bat=fopen(bigbuffer2, "r");
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, bw);
	strcat(bigbuffer2, ".txt");
	bowl=fopen(bigbuffer2, "r");
	dl=fopen("dl.txt", "r");
	
	fscanf(bat,"%s", batfnm);
	fscanf(bat,"%s", batlnm);
	fscanf(bat,"%f", &btav1);
	fscanf(bat,"%f", &btsr1);
	fscanf(bat,"%f", &bwav1);
	fscanf(bat,"%f", &bwsr1);

	fscanf(bowl,"%s", bowlfnm);
	fscanf(bowl,"%s", bowllnm);
	fscanf(bowl,"%f", &btav2);
	fscanf(bowl,"%f", &btsr2);
	fscanf(bowl,"%f", &bwav2);
	fscanf(bowl,"%f", &bwsr2);

	

	out1= 100*(btav1/btsr1);
	
	sr2=(bwav2/bwsr2)*100;
	
	out=(out1*bwsr2)/34.71; //This is the factor to decide if batsman survives or not. More factors can be added on later.

	sr=(btsr1*sr2)/80.67; // This is for scoring rate. More factors can be applied here too.

	fseek(dl, 56*(j)+5*(m-2), SEEK_SET);
	fscanf(dl,"%f", &resrem);
	fseek(dl, 56*(j+1)+5*(m-2), SEEK_SET);
	fscanf(dl,"%f", &resover);
	fseek(dl, 56*(j)+5*(m-1), SEEK_SET);
	fscanf(dl,"%f", &reswicket);
	resrem=resrem/100;
	resover=resover/100;
	reswicket=reswicket/100;
	

	r0=((-0.3651*sr) + 81.513)*10; // Took data of 3 random matches. Used linear regression to find these values. 
					// Will continue it further later. Values can be changed easily. 

	r1=((0.1356*sr) + 22.701)*10;

	r2=((0.0873*sr) - 0.8742)*10;

	r4=((0.0922*sr) - 1.3612)*10;		

	r6=((0.0426*sr) - 1.9615)*10;

	r3=1000-r1-r2-r4-r6-r0;

	
	//printf("%f ()()()() ", e1);
	
	
	
	
	//r0=c*r0;
	pw=(1/out);
	p0=r0*(1-pw)/1000;
	p1=r1*(1-pw)/1000;
	p2=r2*(1-pw)/1000;
	p3=r3*(1-pw)/1000;
	p4=r4*(1-pw)/1000;
	p6=r6*(1-pw)/1000;

	e1=(p1+2*p2+3*p3+4*p4+6*p6);
	e2=(resrem-resover)/6 + pw*(resrem-reswicket);
	batqual=e1/e2;
	reqrate=(t1runs-t2runs+1)/resrem;
	c=e1/(e2*reqrate);

	if(c>1.25)
	c=1.25;
	p0=c*p0;
	gamma=e2/(e2+(resrem-reswicket)*(1-pw-p0));
	
	pw=pw + gamma*p0*(1-c);

	//p2=(1-pw-(c+gamma*(1-c))*p0)*p2/(1-pw-p0);
				
	//p3=(1-pw-(c+gamma*(1-c))*p0)*p3/(1-pw-p0);
	
	//p4=(1-pw-(c+gamma*(1-c))*p0)*p4/(1-pw-p0);
	
	//p6=(1-pw-(c+gamma*(1-c))*p0)*p6/(1-pw-p0);

	r0=p0*1000/(1-pw);
	out=1/pw;
	
	sr=(r0/10 - 82.657)/(-0.3901);

	r1=((0.1646*sr) + 21.351)*10;

	r2=((0.0874*sr) - 0.6926)*10;

	r4=((0.0919*sr) - 1.5526)*10;		

	r6=((0.0396*sr) - 1.8149)*10;
	

	printf("c -- %f, sr --- %f\n", c, sr);
	
	

	

	/*	if(ran[i]<(1000*pw))
		runb=-1;
		else if (ran[i]<(1000*(p0+pw)))
		runb=0; 
		else if (ran[i]<(1000*(p0+p1+pw)))
		runb=1;
		else if (ran[i]<(1000*(p0+p1+p2+pw)))
		runb=2;
		else if (ran[i]<(1000*(p0+p1+p2+p4+pw)))
		runb=4;
		else if (ran[i]<(1000*(p0+p1+p2+p4+p6+pw)))				
		runb=6;
		else
		runb=3;
                                */

	
		if(ran[i+1]<(1000/out))
		runb=-1;
		else if (ran[i]<(r0))
		runb=0; 
		else if (ran[i]<(r0+r1))
		runb=1;
		else if (ran[i]<(r0+r1+r2))
		runb=2;
		else if (ran[i]<(r0+r1+r2+r4))
		runb=4;
		else if (ran[i]<(r0+r1+r2+r4+r6))				
		runb=6;
		else
		runb=3;
	fclose(bat);
	fclose(bowl);
	fclose(dl);
	

	return(runb);

}



void bowlorder(void)
{

	FILE *pl;
	int z, y;
	char buffer[20];
	float buffer1, bwavordt1[12], bwavordt2[12], a[12], b[12], temp;
	char temp2[5] ,temp3[5];
	FILE *tbord;
	char bigbuffer2[100];

	for(z=1; z<12; z++)
	{
		strcpy(team1pbowl[z],team1p[z]);

	}

	for(z=1; z<12; z++)
	{

		
	strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, team1pbowl[z]);
	strcat(bigbuffer2, ".txt");
	
		pl=fopen(bigbuffer2, "r");
		fscanf(pl,"%s", team1pfname[z]);
		fscanf(pl,"%s", team1plname[z]);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &bwavordt1[z]);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%s", bwtypet1[z]);
		
		fclose(pl);
	}

	
	for(y=1; y<12; y++)
	{

		if(strcmp(bwtypet1[y], "wk")==0)
		{
			wkt1=y;
			break;
		}	


	}
	/*for(y=1; y<12; y++)
	{
		for(z=1; z<11; z++)
		{
			if(bwavordt1[z]>bwavordt1[z+1])
			{
				temp=bwavordt1[z];
				bwavordt1[z]=bwavordt1[z+1];
				bwavordt1[z+1]=temp;
				strcpy(temp2, team1pbowl[z]);
				strcpy(team1pbowl[z], team1pbowl[z+1]);
				strcpy(team1pbowl[z+1], temp2);
				strcpy(temp3, bwtypet1[z]);
				strcpy(bwtypet1[z], bwtypet1[z+1]);
				strcpy(bwtypet1[z+1], temp3);
					
			}
		}	

	}
	
	for(y=0; y<5; y++)
	{
		for(z=1; z<5; z++)
		{
			if(strcmp(bwtypet1[z],"ros")==0 || strcmp(bwtypet1[z],"rlb")==0 || strcmp(bwtypet1[z],"las")==0)
			{
				strcpy(temp2, team1pbowl[z]);
				strcpy(team1pbowl[z], team1pbowl[z+1]);
				strcpy(team1pbowl[z+1], temp2);
				strcpy(temp3, bwtypet1[z]);
				strcpy(bwtypet1[z], bwtypet1[z+1]);				
                        	strcpy(bwtypet1[z+1], temp3);		
			}
	
		}

	}*/
	
	strcpy(t1bord, team1);
	strcat(t1bord, "bord");
	strcpy(t2bord, team2);
	strcat(t2bord, "bord");	
	
	strcpy(bigbuffer2, "Data/Teams/");
	strcat(bigbuffer2, t1bord);
	strcat(bigbuffer2, ".txt");
	
	tbord=fopen(bigbuffer2, "r");
	for(l=1; l<6; l++)
	{
		fscanf(tbord, "%s", team1pbowl[l]);

	}

	for(z=1; z<6; z++)
	{

		
		strcpy(bigbuffer2, "Data/Players/");
		strcat(bigbuffer2, team1pbowl[z]);
		strcat(bigbuffer2, ".txt");
		pl=fopen(bigbuffer2, "r");
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%s", bwtypet1[z]);
		
		fclose(pl);
	}


	
	
	fclose(tbord);
		
	for(z=1; z<12; z++)
	{
		strcpy(team2pbowl[z],team2p[z]);

	}

	for(z=1; z<12; z++)
	{

		
		strcpy(bigbuffer2, "Data/Players/");
		strcat(bigbuffer2, team2pbowl[z]);
		strcat(bigbuffer2, ".txt");
		pl=fopen(bigbuffer2, "r");
		fscanf(pl,"%s", team2pfname[z]);
		fscanf(pl,"%s", team2plname[z]);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &bwavordt2[z]);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%s", bwtypet2[z]);
		
		fclose(pl);
	}
	for(y=1; y<12; y++)
	{

		if(strcmp(bwtypet2[y], "wk")==0)
		{
			wkt2=y;
			break;
		}	


	}

	
	
	/*for(y=1; y<12; y++)
	{
		for(z=1; z<11; z++)
		{
			if(bwavordt2[z]>bwavordt2[z+1])
			{
				temp=bwavordt2[z];
				bwavordt2[z]=bwavordt2[z+1];
				bwavordt2[z+1]=temp;
				strcpy(temp2, team2pbowl[z]);
				strcpy(team2pbowl[z], team2pbowl[z+1]);
				strcpy(team2pbowl[z+1], temp2);
				strcpy(temp3, bwtypet2[z]);
				strcpy(bwtypet2[z], bwtypet2[z+1]);
				strcpy(bwtypet2[z+1], temp3);
					
			}
		}	

	}
	
	for(y=0; y<5; y++)
	{
		for(z=1; z<5; z++)
		{
			if(strcmp(bwtypet2[z],"ros")==0 || strcmp(bwtypet2[z],"rlb")==0 || strcmp(bwtypet2[z],"las")==0)
			{
				strcpy(temp2, team2pbowl[z]);
				strcpy(team2pbowl[z], team2pbowl[z+1]);
				strcpy(team2pbowl[z+1], temp2);
				strcpy(temp3, bwtypet2[z]);
				strcpy(bwtypet2[z], bwtypet2[z+1]);				
                        	strcpy(bwtypet2[z+1], temp3);		
			}
	
		}

	}*/

	strcpy(bigbuffer2, "Data/Teams/");
	strcat(bigbuffer2, t2bord);
	strcat(bigbuffer2, ".txt");
	tbord=fopen(bigbuffer2, "r");
	for(l=1; l<6; l++)
	{
		fscanf(tbord, "%s", team2pbowl[l]);

	}

	for(z=1; z<6; z++)
	{

		strcpy(bigbuffer2, "Data/Players/");
	strcat(bigbuffer2, team2pbowl[z]);
	strcat(bigbuffer2, ".txt");

		pl=fopen(bigbuffer2, "r");
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%f", &buffer1);
		fscanf(pl,"%s", buffer);
		fscanf(pl,"%s", bwtypet2[z]);
		
		fclose(pl);
	}
	
	
	fclose(tbord);
	
	
	
}

void comm0p(void)
{	

	comm[i]=comm[i]%20;
	if(comm[i]==0)
	{
		printf("keeps this outside off and %s defends compactly into the off side.\n", batlnm);
		fprintf(fcomm, "keeps this outside off and %s defends compactly into the off side.\n", batlnm);
	}

	if(comm[i]==1)
	{
		printf("fuller length, on middle and leg, it was there for the on drive, but %s played it straight to mid on.\n", batlnm);
		fprintf(fcomm, "fuller length, on middle and leg, it was there for the on drive, but %s played it straight to mid on.\n", batlnm);
	} 	

	if(comm[i]==2)
	{
		printf("that came off the track slower than %s expected as he shaped to cut. Not much room either and he ended up bottom edging it away to the off side. \n", batlnm);
		fprintf(fcomm, "that came off the track slower than %s expected as he shaped to cut. Not much room either and he ended up bottom edging it away to the off side. \n", batlnm);
	}

	if(comm[i]==3)
	{
		printf("back of a length, flat and quick, %s gets half forward and defends.\n", batlnm);
		fprintf(fcomm, "back of a length, flat and quick, %s gets half forward and defends.\n", batlnm);
	}
	
	if(comm[i]==4)
	{
		printf("fuller length, it was there for the drive, %s got forward nicely but chose to check the drive towards mid off. \n", batlnm);
		fprintf(fcomm,"fuller length, it was there for the drive, %s got forward nicely but chose to check the drive towards mid off. \n", batlnm);
	}
	if(comm[i]==5)
	{
		printf("short of good length outside off, %s hangs back and forces it towards cover point. \n", batlnm);
		fprintf(fcomm, "short of good length outside off, %s hangs back and forces it towards cover point. \n", batlnm);
	}	
	if(comm[i]==6)
	{
		printf("fuller length, on the perfect line just outside off, %s covers the line and defends.\n", batlnm);
		fprintf(fcomm, "fuller length, on the perfect line just outside off, %s covers the line and defends.\n", batlnm);
	}
		
	if(comm[i]==7)
	{
		printf("slower ball on a length outside off, %s stays on the backfoot and punches into the covers. \n", batlnm);
		fprintf(fcomm, "slower ball on a length outside off, %s stays on the backfoot and punches into the covers. \n", batlnm);
	}
	if(comm[i]==8)
	{
		printf("fuller, gets %s to come forward and defend. \n", batlnm);
		fprintf(fcomm, "fuller, gets %s to come forward and defend. \n", batlnm);
	}	
	if(comm[i]==9)
	{
		printf("back of a length outside off and %s defends into the off side. \n", batlnm);
		fprintf(fcomm, "back of a length outside off and %s defends into the off side. \n", batlnm);
	}	
	if(comm[i]==10)
	{
		printf("angling in towards the pads, %s gets the front foot across and works it to square leg. \n", batlnm);
		fprintf(fcomm, "angling in towards the pads, %s gets the front foot across and works it to square leg. \n", batlnm);
	}
	
	if(comm[i]==11)
	{
		printf("tucks this off the pads straight to midwicket.  \n");
		fprintf(fcomm, "tucks this off the pads straight to midwicket. \n");
	}

	if(comm[i]==12)
	{
		printf("plays from the crease at quite a full delivery, takes an inside to square leg. %s wanted the single but was sent back. \n", batlnm);
		fprintf(fcomm, "plays from the crease at quite a full delivery, takes an inside to square leg. %s wanted the single but was sent back. \n", batlnm);
	}

	if(comm[i]==13)
	{
		printf("good length outside off, hint of shape back into %s who defends into the covers. \n", batlnm);
		fprintf(fcomm, "good length outside off, hint of shape back into %s who defends into the covers. \n", batlnm);
	}

	if(comm[i]==14)
	{
		printf("back of a length, closer to off stump, defended to the off side.\n");
		fprintf(fcomm, "back of a length, closer to off stump, defended to the off side. \n");
	}

	if(comm[i]==15)
	{
		printf("touch of extra bounce and %s takes his bottom hand off the bat as he plays to the leg side. \n", batlnm);
		fprintf(fcomm, "touch of extra bounce and %s takes his bottom hand off the bat as he plays to the leg side. \n", batlnm);
	}

	if(comm[i]==16)
	{
		printf("short of a length outside off and left alone.  \n");
		fprintf(fcomm, "short of a length outside off and left alone.  \n");
	}

	if(comm[i]==17)
	{
		printf("this is fuller from %s and %s leans into a well-timed drive but picks out mid-off. \n", bowllnm, batlnm);
		fprintf(fcomm, "this is fuller from %s and %s leans into a well-timed drive but picks out mid-off. \n", bowllnm, batlnm);
	}

	if(comm[i]==18)
	{
		printf("drags the length back, punched off the back foot and well fielded at cover. \n");
		fprintf(fcomm, "drags the length back, punched off the back foot and well fielded at cover. \n");
	}

	if(comm[i]==19)
	{
		printf("pushed across outside off, %s makes a big stride forward and defends to the covers.\n", batlnm);
		fprintf(fcomm, "pushed across outside off, %s makes a big stride forward and defends to the covers.\n", batlnm);
	}
	
	


}

void comm1p(void)
{
	comm[i]=comm[i]%21;
	
	if(comm[i]==0)
	{
		printf("nips back at %s who works it behind square leg on the leg side.\n", batlnm);
		fprintf(fcomm, "nips back at %s who works it behind square leg on the leg side.\n", batlnm);
	}

	if(comm[i]==1)
	{
		printf("throws his arms through a drive this time, it was very wide and the ball went in the air through cover out to the sweeper. \n");
		fprintf(fcomm, "throws his arms through a drive this time, it was very wide and the ball went in the air through cover out to the sweeper. \n");
	}

	if(comm[i]==2)
	{
		printf("jumps back into the crease and nudges this from around off stump to the leg side.\n");
		fprintf(fcomm, "jumps back into the crease and nudges this from around off stump to the leg side.\n");
	}

	if(comm[i]==3)
	{
		printf("short of length again, but a little straighter this time and %s works a single wide of mid on.\n", batlnm);
		fprintf(fcomm, "short of length again, but a little straighter this time and %s works a single wide of mid on.\n", batlnm);
	}

	if(comm[i]==4)
	{
		printf("chopped down on the off side, just the one\n");
		fprintf(fcomm, "chopped down on the off side, just the one\n");
	}

	if(comm[i]==5)
	{
		printf("a hacked drive played with a horizontal bat flies out to deep cover, where there's protection on the rope.\n");
		fprintf(fcomm, "a hacked drive played with a horizontal bat flies out to deep cover, where there's protection on the rope.\n");
	}

	if(comm[i]==6)
	{
		printf("pitched full and wide by %s, and %s eases a drive to cover.\n", bowllnm, batlnm);
		fprintf(fcomm, "pitched full and wide by %s, and %s eases a drive to cover.\n", bowllnm, batlnm);
	}

	if(comm[i]==7)
	{
		printf("nurdled into the off side for one.\n");
		fprintf(fcomm, "nurdled into the off side for one.\n");
	}

	if(comm[i]==8)
	{
		printf("worked away for a quiet single.\n");
		fprintf(fcomm, "worked away for a quiet single.\n");
	}

	if(comm[i]==9)
	{
		printf("a well played shot for just one run, %s stepping confidently forward and driving wide of mid off. %s sprinted to his left and tumbled into a sliding stop to keep him to just on.\n", batlnm, fieldlnm);
		fprintf(fcomm, "a well played shot for just one run, %s stepping confidently forward and driving wide of mid off. %s sprinted to his left and tumbled into a sliding stop to keep him to just on.\n", batlnm, fieldlnm);
	}

	if(comm[i]==10)
	{
		printf("much fuller and straighter, and cutting in off the wicket. %s spots the change-up and gets forward to defend to mid on.\n", batlnm);
		fprintf(fcomm, "much fuller and straighter, and cutting in off the wicket. %s spots the change-up and gets forward to defend to mid on.\n", batlnm);
	}

	if(comm[i]==11)
	{
		printf("whipped off the pads, the ball rolling behind square on the leg side.\n");
		fprintf(fcomm, "whipped off the pads, the ball rolling behind square on the leg side.\n");
	}

	if(comm[i]==12)
	{
		printf("%s's strong bottom hand sends this past short midwicket, from outside off .\n", batlnm);
		fprintf(fcomm, "%s's strong bottom hand sends this past short midwicket, from outside off .\n", batlnm);
	}

	if(comm[i]==13)
	{
		printf("length ball, angling in, worked away for a single.\n");
		fprintf(fcomm, "length ball, angling in, worked away for a single.\n");
	}

	if(comm[i]==14)
	{
		printf("walks across to this, clips it off the pads, from outside off, for a single.\n");
		fprintf(fcomm, "walks across to this, clips it off the pads, from outside off, for a single.\n");
	}

	if(comm[i]==15)
	{
		printf("short of a length, on off, flicked away to deep square leg.\n");
		fprintf(fcomm, "short of a length, on off, flicked away to deep square leg.\n");
	}

	if(comm[i]==16)
	{
		printf("bouncer, 144.5ks, on off, chest high, pulls it, and keeps it down.\n");
		fprintf(fcomm, "bouncer, 144.5ks, on off, chest high, pulls it, and keeps it down .\n");
	}

	if(comm[i]==17)
	{
		printf("short of a length, outside off, runs it down for a single.\n");
		fprintf(fcomm, "short of a length, outside off, runs it down for a single.\n");
	}

	if(comm[i]==18)
	{
		printf("length, angling in, pushed past short midwicket.\n");
		fprintf(fcomm, "length, angling in, pushed past short midwicket.\n");
	}
	

	if(comm[i]==19)
	{
		printf("length ball, outside off, holds its line, %s opens the face and takes a single.\n", batlnm);
		fprintf(fcomm, "length ball, outside off, holds its line, %s opens the face and takes a single.\n", batlnm);
	}

	if(comm[i]==20)
	{
		printf("length ball, on leg, flicked away for a single past midwicket.\n");
		fprintf(fcomm, "length ball, on leg, flicked away for a single past midwicket.\n");
	}
}	

void comm2p(void)
{
	comm[i]=comm[i]%17;		

	if(comm[i]==0)
	{
		printf("nips back atangling into the pads, deflected to the left of short fine. %s makes a diving save, but the ball hits the hand and ricochets to deep square to allow them the second.\n", fieldlnm);
		fprintf(fcomm, "nips back atangling into the pads, deflected to the left of short fine. %s makes a diving save, but the ball hits the hand and ricochets to deep square to allow them the second.\n", fieldlnm);
	}

	if(comm[i]==1)
	{
		printf("full, outside off, the bottom hand comes in, resulting in a thick inside edge for a couple square of long leg.\n");
		fprintf(fcomm, "full, outside off, the bottom hand comes in, resulting in a thick inside edge for a couple square of long leg.\n");
	}

	if(comm[i]==2)
	{
		printf("tucked away off the hip, between long leg and deep square, comes back for two. The throw has to come into the wind, so it's an easy second. \n");
		fprintf(fcomm, "tucked away off the hip, between long leg and deep square, comes back for two. The throw has to come into the wind, so it's an easy second. \n");
	}

	if(comm[i]==3)
	{
		printf("full, on the pads, whipped away square of deep square leg, where our man %s makes a diving save.\n", fieldlnm);
		fprintf(fcomm, "full, on the pads, whipped away square of deep square leg, where our man %s makes a diving save.\n", fieldlnm);
	}

	if(comm[i]==4)
	{
		printf("full, on the pads, flicked away square, %s makes another diving save to save two runs here.\n", fieldlnm);
		fprintf(fcomm, "full, on the pads, flicked away square, %s makes another diving save to save two runs here.\n", fieldlnm);
	}

	if(comm[i]==5)
	{
		printf("length ball, on off, crisply push-driven, past cover, gets a couple.\n");
		fprintf(fcomm, "length ball, on off, crisply push-driven, past cover, gets a couple.\n");
	}

	if(comm[i]==6)
	{
		printf("length ball, on leg, flicked away for a single past midwicket.\n");
		fprintf(fcomm, "length ball, on leg, flicked away for a single past midwicket.\n");
	}

	if(comm[i]==7)
	{
		printf("slow again, 113ks, pulled away wide of long-on for two.\n");
		fprintf(fcomm, "slow again, 113ks, pulled away wide of long-on for two.\n");
	}

	if(comm[i]==8)
	{
		printf("length ball, thumped on the up, between long-on and long-off, gets a couple.\n");
		fprintf(fcomm, "length ball, thumped on the up, between long-on and long-off, gets a couple.\n");
	}

	if(comm[i]==9)
	{
		printf("short, pulled wide of long-on, where %s fields. They take the second, %s is not quite by the stumps to collect the throw. Would have been very close had he done so.\n", fieldlnm, bowllnm);
		fprintf(fcomm, "short, pulled wide of long-on, where %s fields. They take the second, %s is not quite by the stumps to collect the throw. Would have been very close had he done so.\n", fieldlnm, bowllnm);
	}


	if(comm[i]==10)
	{
		printf("nicely opens the face on this quick length ball, to the left of third man.\n");
		fprintf(fcomm, "nicely opens the face on this quick length ball, to the left of third man.\n");
	}


	if(comm[i]==11)
	{
		printf("slower ball on off, worked square on the on side with soft hands, comes back for two.\n");
		fprintf(fcomm, "slower ball on off, worked square on the on side with soft hands, comes back for two.\n");
	}


	if(comm[i]==12)
	{
		printf("%s continues to look threatening, pulls this to cow corner. %s from long-on has to give it a big chase and a final lunge to keep them down to two.\n", batlnm, fieldlnm);
		fprintf(fcomm, "%s continues to look threatening, pulls this to cow corner. %s from long-on has to give it a big chase and a final lunge to keep them down to two.\n", batlnm, fieldlnm);
	}


	if(comm[i]==13)
	{
		printf("%s does the Ganguly routine again, he leaps out and cracks a wide ball up and over point. He doesn't time it, though, and sweeper covers comes around to field it. The man from the deep yorks the keeper with a horror throw and they get a second. And then next throw back is also wide.\n", batlnm);
		fprintf(fcomm, "%s does the Ganguly routine again, he leaps out and cracks a wide ball up and over point. He doesn't time it, though, and sweeper covers comes around to field it. The man from the deep yorks the keeper with a horror throw and they get a second. And then next throw back is also wide.\n", batlnm);
	}


	if(comm[i]==14)
	{
		printf("shaped into the pads again, this time %s works it nicely through square leg and sprints back for two.\n", batlnm);
		fprintf(fcomm, "shaped into the pads again, this time %s works it nicely through square leg and sprints back for two.\n", batlnm);
	}

	if(comm[i]==15)
	{
		printf("length ball on the pads, %s nudges square for another couple.\n", batlnm);
		fprintf(fcomm, "length ball on the pads, %s nudges square for another couple.\n", batlnm);

	}


	if(comm[i]==16)
	{
		printf("%s looks to clear mid-off, but doesn't time it at all. He manages to get over the fielder, only just, and gets a couple.\n", batlnm);
		fprintf(fcomm, "%s looks to clear mid-off, but doesn't time it at all. He manages to get over the fielder, only just, and gets a couple.\n", batlnm);
	}


	


}

void comm0s(void)
{
	comm[i]=comm[i]%20 +1;

	if(comm[i]==1)
	{
		printf("overpitched on the pads, pushed to midwicket.\n");
		fprintf(fcomm, "overpitched on the pads, pushed to midwicket.\n");

	}


	if(comm[i]==2)
	{
		printf("full, on the stumps, drives to leg, but can't beat short midwicket.\n");
		fprintf(fcomm, "full, on the stumps, drives to leg, but can't beat short midwicket.\n");

	}


	if(comm[i]==3)
	{
		printf("slight drift with this one, but too full again. Pushed to short midwicket.\n");
		fprintf(fcomm, "slight drift with this one, but too full again. Pushed to short midwicket.\n");

	}


	if(comm[i]==4)
	{
		printf("looks to cut, but the ball stops at him, ends up hitting it to cover.\n");
		fprintf(fcomm, "looks to cut, but the ball stops at him, ends up hitting it to cover.\n");

	}


	if(comm[i]==5)
	{
		printf("beautiful shot as he takes this from outside leg to go inside-out, but %s makes a diving save at cover.\n", fieldlnm);
		fprintf(fcomm, "beautiful shot as he takes this from outside leg to go inside-out, but %s makes a diving save at cover.\n", fieldlnm);

	}


	if(comm[i]==6)
	{
		printf("turn now. Tossed up outside off, not overpitched, gives it time to turn, and that beats the edge.\n");
		fprintf(fcomm, "turn now. Tossed up outside off, not overpitched, gives it time to turn, and that beats the edge.\n");

	}


	if(comm[i]==7)
	{
		printf("full again, defended back to the bowler.\n");
		fprintf(fcomm, "full again, defended back to the bowler.\n");

	}


	if(comm[i]==8)
	{
		printf("aggression from %s! He doesn't want to let %s settle, and charges down the track at the spinner. He's not quite to the pitch of it, however, and can only drill the ball at mid-on.\n", batlnm, bowllnm);
		fprintf(fcomm, "aggression from %s! He doesn't want to let %s settle, and charges down the track at the spinner. He's not quite to the pitch of it, however, and can only drill the ball at mid-on.\n", batlnm, bowllnm);
	}


	if(comm[i]==9)
	{
		printf("does this keep a bit low? %s stepped back and tried to cut but could only bottom edge it straight into the ground.\n", batlnm);
		fprintf(fcomm, "does this keep a bit low? %s stepped back and tried to cut but could only bottom edge it straight into the ground.\n", batlnm);

	}
	
	if(comm[i]==10)
	{
		printf("tapped defensively to point.\n");
		fprintf(fcomm, "tapped defensively to point.\n");

	}

	if(comm[i]==11)
	{
		printf("tossed up nice and full from round the wicket, %s driving back to the bowler.\n", batlnm);
		fprintf(fcomm, "tossed up nice and full from round the wicket, %s driving back to the bowler.\n", batlnm);

	}

	if(comm[i]==12)
	{
		printf("%s comes forward to defend to cover.\n", batlnm);
		fprintf(fcomm, "%s comes forward to defend to cover.\n", batlnm);

	}

	if(comm[i]==13)
	{
		printf("full again, defended back to the bowler.\n");
		fprintf(fcomm, "full again, defended back to the bowler.\n");

	}

	if(comm[i]==14)
	{
		printf("turn and bounce for the spinner! This gripped and spat off the surface, leaping past the shoulder of %s's bat.\n", batlnm);
		fprintf(fcomm, "turn and bounce for the spinner! This gripped and spat off the surface, leaping past the shoulder of %s's bat.\n", batlnm);

	}

	if(comm[i]==15)
	{
		printf("driven softly to extra cover.\n");
		fprintf(fcomm, "driven softly to extra cover.\n");

	}

	if(comm[i]==16)
	{
		printf("%s comes forward once again to push to cover, but hits the fielder.\n", batlnm);
		fprintf(fcomm, "%s comes forward once again to push to cover, but hits the fielder.\n", batlnm);

	}

	if(comm[i]==17)
	{
		printf("flicked from outside off along the ground to midwicket where %s makes a good save.\n", fieldlnm);
		fprintf(fcomm, "flicked from outside off along the ground to midwicket where %s makes a good save.\n", fieldlnm);

	}

	if(comm[i]==18)
	{
		printf("round the wicket, driven to cover.\n");
		fprintf(fcomm, "round the wicket, driven to cover.\n");

	}

	if(comm[i]==19)
	{
		printf("chopped down to short third man.\n");
		fprintf(fcomm, "chopped down to short third man.\n");

	}

	if(comm[i]==20)
	{
		printf("beats the outside edge with one that doesn't turn. %s appeals for a stumping but the back foot hadn't moved.\n", wklnm);
		fprintf(fcomm, "beats the outside edge with one that doesn't turn. %s appeals for a stumping but the back foot hadn't moved.\n", wklnm);

	}



}


void comm1s(void)
{
	
	comm[i]=comm[i]%13;

	if(comm[i]==0)
	{
		printf("touch too straight from the spinner, and %s finds the gap at square leg.\n", batlnm);
		fprintf(fcomm, "touch too straight from the spinner, and %s finds the gap at square leg.\n", batlnm);

	}

	if(comm[i]==1)
	{
		printf("quicker and flatter through the air from %s, but it's dragged down short and %s eases a single to leg .\n", bowllnm, batlnm);
		fprintf(fcomm, "quicker and flatter through the air from %s, but it's dragged down short and %s eases a single to leg .\n", bowllnm, batlnm);

	}

	if(comm[i]==2)
	{
		printf("good stuff from %s, getting deep in the crease and placing the ball square for another single. \n", batlnm);
		fprintf(fcomm, "good stuff from %s, getting deep in the crease and placing the ball square for another single. \n", batlnm);

	}

	if(comm[i]==3)
	{
		printf("hurled down quicker and flatter, and after coming down %s double-bluffs the bowler by stepping deep into his crease to work a single into the leg side.\n", batlnm);
		fprintf(fcomm, "hurled down quicker and flatter, and after coming down %s double-bluffs the bowler by stepping deep into his crease to work a single into the leg side.\n", batlnm);

	}

	if(comm[i]==4)
	{
		printf("work off the hip to square leg.\n");
		fprintf(fcomm, "work off the hip to square leg.\n");

	}

	if(comm[i]==5)
	{
		printf("too full again, pushed for an easy single to cover.\n");
		fprintf(fcomm, "too full again, pushed for an easy single to cover.\n");

	}

	if(comm[i]==6)
	{
		printf("overpitched, outside off, driven to long-on for one.\n");
		fprintf(fcomm, "overpitched, outside off, driven to long-on for one.\n");

	}

	if(comm[i]==7)
	{
		printf("length ball, angling into the pads, pushed to mid-on who is at the edge of the circle.\n");
		fprintf(fcomm, "length ball, angling into the pads, pushed to mid-on who is at the edge of the circle.\n");

	}

	if(comm[i]==8)
	{
		printf("short, stays low, but he punches it to long-on for one.\n");
		fprintf(fcomm, "short, stays low, but he punches it to long-on for one. \n");

	}

	if(comm[i]==9)
	{
		printf("full, middle and off, driven past %s for one.\n", bowllnm);
		fprintf(fcomm, "full, middle and off, driven past %s for one.\n", bowllnm);

	}

	if(comm[i]==10)
	{
		printf("length ball, just outside off, stays back to dab it fine of short third for a single.\n");
		fprintf(fcomm, "length ball, just outside off, stays back to dab it fine of short third for a single.\n");

	}

	if(comm[i]==11)
	{
		printf("driven down to long-on for one.\n");
		fprintf(fcomm, "driven down to long-on for one.\n");

	}

	if(comm[i]==12)
	{
		printf("overpitched, on the pads, clipped away to deep midwicket.\n");
		fprintf(fcomm, "overpitched, on the pads, clipped away to deep midwicket.\n");

	}

}

void comm4p(void)
{
	
	comm[i]=comm[i]%22;

	if(comm[i]==0)
	{
		printf("just a hint of width and %s takes advantage with a strong square drive...the ball flies away at this ground.\n", batlnm);
		fprintf(fcomm, "just a hint of width and %s takes advantage with a strong square drive...the ball flies away at this ground.\n", batlnm);

	}

	if(comm[i]==1)
	{
		printf("dispatched through the covers, it was a wide half volley and %s was able to free his arms with a booming drive.\n", batlnm);
		fprintf(fcomm, "dispatched through the covers, it was a wide half volley and %s was able to free his arms with a booming drive.\n", batlnm);

	}


	if(comm[i]==2)
	{
		printf("sends down a big full toss which is hammered straight down the ground...it didn't actually come out of the middle, but didn't matter.\n");
		fprintf(fcomm, "sends down a big full toss which is hammered straight down the ground...it didn't actually come out of the middle, but didn't matter.\n");

	}


	if(comm[i]==3)
	{
		printf("too straight and clipped away through midwicket.\n");
		fprintf(fcomm, "too straight and clipped away through midwicket.\n");

	}


	if(comm[i]==4)
	{
		printf("width outside off this time, and too short, allows %s to punch it off the back foot through the covers.\n", batlnm);
		fprintf(fcomm, "width outside off this time, and too short, allows %s to punch it off the back foot through the covers.\n", batlnm);

	}


	if(comm[i]==5)
	{
		printf("on leg stump again, easy for %s as he whips it through square leg.\n", batlnm);
		fprintf(fcomm, "on leg stump again, easy for %s as he whips it through square leg.\n", batlnm);

	}


	if(comm[i]==6)
	{
		printf("close! Finds the inside edge and it flies past the out-stretched left hand of %s..he got a fingertip on it, mighty tough as he had to change direction.\n", wklnm);
		fprintf(fcomm, "close! Finds the inside edge and it flies past the out-stretched left hand of %s..he got a fingertip on it, mighty tough as he had to change direction.\n", wklnm);

	}


	if(comm[i]==7)
	{
		printf("slashed square! Again %s had to stretch out to drive but this time played it a little later to pick the gap.\n", batlnm);
		fprintf(fcomm, "slashed square! Again %s had to stretch out to drive but this time played it a little later to pick the gap.\n", batlnm);

	}

	if(comm[i]==8)
	{
		printf("%s dispatches a short ball to long leg with a cracking swivel-pull! That was sweetly timed, it never got up high but bounced just once before crossing the boundary.\n", batlnm);
		fprintf(fcomm, "%s dispatches a short ball to long leg with a cracking swivel-pull! That was sweetly timed, it never got up high but bounced just once before crossing the boundary.\n", batlnm);

	}

	if(comm[i]==9)
	{
		printf("%s dispatches a short ball to long leg with a cracking swivel-pull! That was sweetly timed, it never got up high but bounced just once before crossing the boundary.\n", batlnm);
		fprintf(fcomm, "%s dispatches a short ball to long leg with a cracking swivel-pull! That was sweetly timed, it never got up high but bounced just once before crossing the boundary.\n", batlnm);

	}

	if(comm[i]==10)
	{
		printf("in the air! %s pitched one up and lured %s into a drive. It wasn't quite close enough to him for the shot, however, and he couldn't keep the square drive down, the ball shooting just past a leaping %s.\n", bowllnm, batlnm, fieldlnm);
		fprintf(fcomm, "in the air! %s pitched one up and lured %s into a drive. It wasn't quite close enough to him for the shot, however, and he couldn't keep the square drive down, the ball shooting just past a leaping %s.\n", bowllnm, batlnm, fieldlnm);

	}

	if(comm[i]==11)
	{
		printf("edged to third man! There is a slip in place but this was far too wide for him. %s was aiming for a backfoot punch to cover, but %s shaped one away from him to take a healthy edge. Unfortunately for him, it flew at a catchable height through the vacant second/third slip area .\n", batlnm, bowllnm);
		fprintf(fcomm, "edged to third man! There is a slip in place but this was far too wide for him. %s was aiming for a backfoot punch to cover, but %s shaped one away from him to take a healthy edge. Unfortunately for him, it flew at a catchable height through the vacant second/third slip area .\n", batlnm, bowllnm);
	}

	if(comm[i]==12)
	{
		printf("wide half-volley, leans into it, and drives it magnificently between mid-off and extra cover. Oh how easy %s makes them look.\n", batlnm); 
		fprintf(fcomm, "wide half-volley, leans into it, and drives it magnificently between mid-off and extra cover. Oh how easy %s makes them look.\n", batlnm); 
	}

	if(comm[i]==13)
	{
		printf("lovely off-drive. This is hardly a half-volley, but he meets it with a straight bat, on the up, and sends it speeding between the bowler and mid-off.\n");
		fprintf(fcomm, "lovely off-drive. This is hardly a half-volley, but he meets it with a straight bat, on the up, and sends it speeding between the bowler and mid-off.\n");

	}

	if(comm[i]==14)
	{
		printf("short and wide, %s sits back and cuts the leather off it. Neither point nor third man has a chance.\n", batlnm);
		fprintf(fcomm, "short and wide, %s sits back and cuts the leather off it. Neither point nor third man has a chance.\n", batlnm);

	}

	if(comm[i]==15)
	{
		printf("this is an even better shot. Gets a length ball on off, presses half-forward, closes the face late, providing the whip with the wrists, placing it wide of mid-on.\n");
		fprintf(fcomm, "this is an even better shot. Gets a length ball on off, presses half-forward, closes the face late, providing the whip with the wrists, placing it wide of mid-on.\n");

	}

	if(comm[i]==16)
	{
		printf("slightly slower, slightly fuller, he drives in front of his body, but drives emphatically, between mid-off and extra cover.\n");
		fprintf(fcomm, "slightly slower, slightly fuller, he drives in front of his body, but drives emphatically, between mid-off and extra cover.\n");

	}

	if(comm[i]==17)
	{
		printf("%s is having one of them days. Length ball, middle and leg, he lofts this over mid-on. Effortless, just goes through the line of the ball. Clears mid-on comfortably.\n", batlnm);
		fprintf(fcomm, "%s is having one of them days. Length ball, middle and leg, he lofts this over mid-on. Effortless, just goes through the line of the ball. Clears mid-on comfortably.\n", batlnm);

	}

	if(comm[i]==18)
	{
		printf("wide outside off, not a half-volley, but he stretches forward, covers the line, and push-drives it with an open face, between mid-off and extra cover. No feet, but arms and hands do the job.\n");
		fprintf(fcomm, "wide outside off, not a half-volley, but he stretches forward, covers the line, and push-drives it with an open face, between mid-off and extra cover. No feet, but arms and hands do the job.\n");

	}

	if(comm[i]==19)
	{
		printf("that is close to what %s wants to do. Length ball, wide, with roo, he pushes forward, the foot gets close to the line of the ball, and then drives on the up. Between mid-off and extra cover..\n", batlnm);
		fprintf(fcomm, "that is close to what %s wants to do. Length ball, wide, with roo, he pushes forward, the foot gets close to the line of the ball, and then drives on the up. Between mid-off and extra cover.\n", batlnm);

	}

	if(comm[i]==20)
	{
		printf("that's some shot for somebody as bottom-handed as %s. Jumps out of the crease, gives himself room, drives inside-out, between mid-off and extra cover.\n", batlnm);
		fprintf(fcomm, "that's some shot for somebody as bottom-handed as %s. Jumps out of the crease, gives himself room, drives inside-out, between mid-off and extra cover.\n", batlnm);

	}

	if(comm[i]==21)
	{
		printf("thick edge, %s won't mind it. %s hits the seam again, and there is extra bounce as %s looks to cut. The edge flies fine, and %s is down on his haunches.\n", batlnm, bowllnm, batlnm, bowllnm);
		fprintf(fcomm, "thick edge, %s won't mind it. %s hits the seam again, and there is extra bounce as %s looks to cut. The edge flies fine, and %s is down on his haunches.\n", batlnm, bowllnm, batlnm, bowllnm);

	}


	
	

}

void comm4s(void)
{
	
	comm[i]=comm[i]%15;

	if(comm[i]==0)
	{
		printf("this is slightly shorter, and grips and turns, but the outside edge beats both keeper and short third man.\n");
		fprintf(fcomm, "this is slightly shorter, and grips and turns, but the outside edge beats both keeper and short third man.\n");

	}

	if(comm[i]==1)
	{
		printf("more turn for %s, this is flat and quick, takes the edge, and goes between keeper and slip. Fortunate runs.\n", bowllnm);
		fprintf(fcomm, "more turn for %s, this is flat and quick, takes the edge, and goes between keeper and slip. Fortunate runs.\n", bowllnm);

	}

	if(comm[i]==2)
	{
		printf("slower through the air, %s comes down the track, right down to the pitch, drives it inside-out, and this time he also manages to beat cover.\n", batlnm);
		fprintf(fcomm, "slower through the air, %s comes down the track, right down to the pitch, drives it inside-out, and this time he also manages to beat cover.\n", batlnm);

	}

	if(comm[i]==3)
	{
		printf("perfect placement! %s picked up the short length and the width in a flash, stepping back and playing a deft late cut that had the beating of the man at short third man.\n", batlnm);
		fprintf(fcomm, "perfect placement! %s picked up the short length and the width in a flash, stepping back and playing a deft late cut that had the beating of the man at short third man.\n", batlnm);

	}

	if(comm[i]==4)
	{
		printf("that's a top shot, uses his feet and dances down outside leg stump then drives inside out over cover...wonderful batting.\n");
		fprintf(fcomm, "that's a top shot, uses his feet and dances down outside leg stump then drives inside out over cover...wonderful batting.\n");

	}

	if(comm[i]==5)
	{
		printf("he's helping himself now, poor bowling from %s, too much width outside off and %s dabs it through short third man.\n", bowllnm, batlnm);
		fprintf(fcomm, "he's helping himself now, poor bowling from %s, too much width outside off and %s dabs it through short third man.\n", bowllnm, batlnm);
	}

	if(comm[i]==6)
	{
		printf("that's pure class. It was tossed up on off stump and %s slotted it wide of mid-off with the perfect drive.\n", batlnm);
		fprintf(fcomm, "that's pure class. It was tossed up on off stump and %s slotted it wide of mid-off with the perfect drive.\n", batlnm);

	}

	if(comm[i]==7)
	{
		printf("the wheels are off. %s dabs this square on the off side and %s makes a hash of the fielding. %s close to exploding.\n", batlnm, fieldlnm, bowllnm);
		fprintf(fcomm, "the wheels are off. %s dabs this square on the off side and %s makes a hash of the fielding. %s close to exploding.\n", batlnm, fieldlnm, bowllnm);

	}

	if(comm[i]==8)
	{
		printf("low full toss outside off and that's easy pickings as it's slotted through the covers.\n");
		fprintf(fcomm, "low full toss outside off and that's easy pickings as it's slotted through the covers.\n");

	}


	if(comm[i]==9)
	{
		printf("deft touch from %s! Again %s is the man beaten, at third man this time, but there's not much he could have done about it. %s placed the ball superbly with a late cut.\n", batlnm, fieldlnm, batlnm);
		fprintf(fcomm, "deft touch from %s! Again %s is the man beaten, at third man this time, but there's not much he could have done about it. %s placed the ball superbly with a late cut.\n", batlnm, fieldlnm, batlnm);

	}


	if(comm[i]==10)
	{
		printf("uses his feet, makes it into a full toss and drives powerful past a diving mid-off...good intent from %s.\n", batlnm);
		fprintf(fcomm, "uses his feet, makes it into a full toss and drives powerful past a diving mid-off...good intent from %s.\n", batlnm);

	}


	if(comm[i]==11)
	{
		printf("not convincing but he flashes this away past slip through short third man, almost defeated by some extra bounce.\n");
		fprintf(fcomm, "not convincing but he flashes this away past slip through short third man, almost defeated by some extra bounce.\n");

	}


	if(comm[i]==12)
	{
		printf("a booming drive results in a thick outside edge that bounces down to the third man boundary for four.\n");
		fprintf(fcomm, "a booming drive results in a thick outside edge that bounces down to the third man boundary for four.\n");

	}


	if(comm[i]==13)
	{
		printf("that's pure class. It was tossed up on off stump and %s slotted it wide of mid-off with the perfect drive.\n", batlnm);
		fprintf(fcomm, "that's pure class. It was tossed up on off stump and %s slotted it wide of mid-off with the perfect drive.\n", batlnm);

	}


	if(comm[i]==14)
	{
		printf("%s on the counter attack! He skips down the track with great confidence and lofts a drive over cover. That shot wasn't too far away from the silly mid off fielder.\n", batlnm);
		fprintf(fcomm, "%s on the counter attack! He skips down the track with great confidence and lofts a drive over cover. That shot wasn't too far away from the silly mid off fielder.\n", batlnm);

	}


	


	

	
	

}



