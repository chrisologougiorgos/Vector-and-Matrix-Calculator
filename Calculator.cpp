#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

void katalogos(int *a);/*Tupwnei ena menou epilogwn kai kalei ton xrhsth na epilexei kapoia apo tis diathesimes energeies. 
						Orisma: enas akeraios (me anafora) o opoios deixnei thn epilogh tou xrhsth.*/

void dhmiourgia_dianusmatos(float *vector,int stoixeia);/*Dhmiourgei enan  pinaka-grammh(dianusma) me ta stoixeia tou na kathorizontai apo tis eisodous tou xrhsth.
														  Orismata: o pinakas-grammh(dianusma) tou opoiou ta stoixeia tha arxikopoihthoun, enas akeraios isos me to plithos
														  twn stoixeiwn autwn.*/ 

void dhmiourgia_pinaka(float **array,int grammes,int sthles);/*Dhmiourgei enan pinaka me ta stoixeia na kathorizontai apo tis eisodous tou xrhsth.
															   Orismata: o pinakas tou opoiou ta stoixeia tha arxikopoihthoun, enas akeraios pou deixnei to plithos twn grammwn,
															   enas akeraios pou deixnei to plithos twn sthlwn tou pinaka.*/
															   

void grapsimo_arxeiou_dianusma(FILE **f,float *array,int plithos);/*Dexetai to onoma enos duadikou arxeiou apo eisodo tou xrhsth(an den uparxei to dhmiourgei) kai apothikeuei
																	se auto ta stoixeia enos dianusmatos. 
																	Orismata: enas deikths se deikth ston fakelo opou tha ginei h apothikeush,to dianusma to opoio tha apothikeutei
																	 sto arxeio, enas akeraios pou deixnei to plithos twn stoixeiwn tou dianusmatos*/  

void grapsimo_arxeiou_pinakas(FILE **f,float **array,int rows,int columns);/*Dexetai to onoma enos duadikou arxeiou apo eisodo tou xrhsth(an den uparxei to dhmiourgei) kai apothikeuei
																			 se auto ta stoixeia enos pinaka.
																			 Orismata: enas deikths se deikth ston fakelo opou tha ginei h apothikeush,to dianusma to opoio tha
																			 apothikeutei sto arxeio, enas akeraios pou deixnei to plithos twn grammwn, enas akeraios pou deixnei to 
																			 plithos twn sthlwn tou pinaka. */  

main()
{
	int choice=10,subchoice=10,plithosd=0,plithosp=0,i,j,k,dd=0,dp=0,check,var=0,praxh,oros1,oros2,epilogh,doc;
	int stoixeia[SIZE],grammes[SIZE],sthles[SIZE],deld[SIZE],delp[SIZE];
	float *dianusma[SIZE],**pinakas[SIZE],sum,arithmos;
	char filename[SIZE];
	FILE *fp;
	int check1,check2;
	
  while(choice!=0)
  {
	
	katalogos(&choice);
	
	 if(choice==1)//Dhmiourgia sustoixias
	 {
			system("cls");
			printf("Epithumeis na dhmioyrghseis ena dianusma h enan pinaka)?\n");
			printf("\n1)Dianusma				2)Pinakas");
			scanf("%d",&subchoice);
			
			if(subchoice==1)//Epilogh dhmiourgias dianusmatos
			{
				plithosd++;
				
				printf("\nDwse to plithos twn stoixeiwn tou dianusmatos: \n");
				scanf("%d",&stoixeia[plithosd]);
				dianusma[plithosd]=(float *)malloc(sizeof(float)*stoixeia[plithosd]);//Dunamikh desmeush mnhmhhs gia to dianusma
				if(!dianusma[plithosd])
				{
					printf("\nAdunamia desmeushs mnhmhs!");
					exit(0);
				}
				
				dhmiourgia_dianusmatos(dianusma[plithosd],stoixeia[plithosd]);
			}
			
			if(subchoice==2)//Epilogh dhmiourgias pinaka
			{	
				plithosp++;
				
				printf("\nDwse to plithos twn grammwn: \n");
				scanf("%d",&grammes[plithosp]);
				printf("\nDwse to plithos twn sthlwn: \n");
				scanf("%d",&sthles[plithosp]);
				
				pinakas[plithosp]=(float **)malloc(sizeof(float *)*grammes[plithosp]);//Dunamikh deusmeush mnhmhhs gia ton pinaka
				if(!pinakas[plithosp])
				{
					printf("\nAdunamia desmeushs mnhmhs!");
					exit(0);
				}
				for(i=0;i<grammes[plithosp];i++)
				{
					pinakas[plithosp][i]=(float *)malloc(sizeof(float)*sthles[plithosp]);
					if(!pinakas[plithosp][i])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
				}
				 
				
				dhmiourgia_pinaka(pinakas[plithosp],grammes[plithosp],sthles[plithosp]);
			}
			
			printf("\n--------------------------------\n");
			system("pause");
			system("cls");
	}
	
	if(choice==2)//Fortwsh sustoixias apo arxeio
	{
			system("cls");
			printf("\nEpithumeis na fortwseis ena dianusma h enan pinaka(me parapanw apo mia grammes KAI sthles)?");
			printf("\n1)Dianusma			2)Pinakas\n");
			scanf("%d",&subchoice);
		
			if(subchoice==1)//Epilogh fortwshs dianusmatos
			{
				plithosd++;
				
				printf("\nTo arxeio periexei :");
				printf("\n1)Ena dianusma			2)Perissotera apo ena dianusmata(me idio arithmo stoixeiwn!)\n");
				scanf("%d",&epilogh);//Kathorismos tou eidous tou arxeiou(arxeio enos h pollwn dianusmatwn)
				
				printf("\nDwse arxeio: ");
				scanf("%s",filename);
				fp=fopen(filename,"r+b");
				
				if(epilogh==1)
				{
					printf("\nDwse to plithos twn stoixeiwn tou dianusmatos: \n");
					scanf("%d",&stoixeia[plithosd]);
					dianusma[plithosd]=(float *)malloc(sizeof(float)*stoixeia[plithosd]);//Dunamikh desmeush mnhmhs gia to dianusma tou opoiou ta stoixeia tha fortwthoun apo to arxeio
					if(!dianusma[plithosd])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
				
					check1=fread(dianusma[plithosd],sizeof(float),stoixeia[plithosd],fp);//Fortwsh twn stoixeiwn tou dianusmatos apo to arxeio
					if(check1!=stoixeia[plithosd])
						printf("\nApotuxia fortwshs dianusmatos!");
				}
				else if(epilogh==2)
				{
					printf("\nDwse to plithos twn stoixeiwn tou dianusmatos: \n");
					scanf("%d",&stoixeia[plithosd]);
					
					epilogh=0;
					while(epilogh<1)
					{
						printf("\nDwse to dianusma tou arxeiou pou theleis na fortwthei: (1,2...)\n");
						scanf("%d",&epilogh);//Kathorismos tou sugkekrimenou dianusmatos pou epithumei o xrhsths na fortwsei apo to arxeio pollwn dianusmatwn
					}
					fseek(fp,sizeof(float)*stoixeia[plithosd]*(epilogh-1),SEEK_SET);
	
					dianusma[plithosd]=(float *)malloc(sizeof(float)*stoixeia[plithosd]);
					if(!dianusma[plithosd])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
				
					check1=fread(dianusma[plithosd],sizeof(float),stoixeia[plithosd],fp);
					if(check1!=stoixeia[plithosd])
						printf("\nApotuxia fortwshs pinaka!");
				}
				fclose(fp);
			}
			
			if(subchoice==2)//Epilogh fortwshs pinaka
			{
				plithosp++;
				
				printf("\nTo arxeio periexei :");
				printf("\n1)Enan pinaka			2)Perissoterous apo enan pinakes(me idio arithmo grammwn kai sthlwn!)\n");
				scanf("%d",&epilogh);//Kathorismos tou eidous tou arxeiou(arxeio enos h pollwn pinakwn)
				
				printf("\nDwse arxeio: \n");
				scanf("%s",filename);
				fp=fopen(filename,"r+b");
				
				if(epilogh==1)
				{
					printf("\nDwse to plithos twn grammwn: \n");
					scanf("%d",&grammes[plithosp]);
					printf("\nDwse to plithos twn sthlwn: \n");
					scanf("%d",&sthles[plithosp]);
				
					pinakas[plithosp]=(float **)malloc(sizeof(float *)*grammes[plithosp]);//Dunamikh desmeush mnhmhs tou pinaka tou opoiou ta stoixeia tha fortwthoun apo to arxeio
					if(!pinakas[plithosp])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
					for(i=0;i<grammes[plithosp];i++)
					{
						pinakas[plithosp][i]=(float *)malloc(sizeof(float)*sthles[plithosp]);
						if(!pinakas[plithosp][i])
						{
							printf("\nAdunamia desmeushs mnhmhs!");
							exit(0);
						}
					}
				 
					for(i=0;i<grammes[plithosp];i++)
					{
						check1=fread(pinakas[plithosp][i],sizeof(float),sthles[plithosp],fp);
						if(check1!=sthles[plithosp])
							printf("\nApotuxia fortwshs pinaka!");
						
						check1=0;
					}
				}
				else if(epilogh==2)
				{
					printf("\nDwse to plithos twn grammwn: \n");
					scanf("%d",&grammes[plithosp]);
					printf("\nDwse to plithos twn sthlwn: \n");
					scanf("%d",&sthles[plithosp]);
					
					epilogh=0;
					while(epilogh<1)
					{
						printf("\nDwse ton pinaka tou arxeiou pou theleis na fortwthei: (1,2...)\n");
						scanf("%d",&epilogh);//Kathorismos tou sugkekrimenou pinaka pou epithumei o xrhsths na fortwsei apo to arxeio pollwn pinakwn
					}
					fseek(fp,sizeof(float)*grammes[plithosp]*sthles[plithosp]*(epilogh-1),SEEK_SET);
	
					pinakas[plithosp]=(float **)malloc(sizeof(float *)*grammes[plithosp]);
					if(!pinakas[plithosp])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
					for(i=0;i<grammes[plithosp];i++)
					{
						pinakas[plithosp][i]=(float *)malloc(sizeof(float)*sthles[plithosp]);
						if(!pinakas[plithosp][i])
						{
							printf("\nAdunamia desmeushs mnhmhs!");
							exit(0);
						}
					}
				
					for(i=0;i<grammes[plithosp];i++)
					{
						check1=fread(pinakas[plithosp][i],sizeof(float),sthles[plithosp],fp);
						if(check1!=sthles[plithosp])
							printf("\nApotuxia fortwshs pinaka!");
						
						check1=0;
					}
				}
				fclose(fp);
			}
			
			printf("\n--------------------------------\n");
			system("pause");
			system("cls");
	} 
	
	if(choice==3)//Provolh diathesimwn sustoixiwn
	{
			system("cls");
			printf("\nEpithumeis na provlhthoun ta diathesima dianusmata h oi diathesimoi pinakes: \n");
			printf("\n1)Dianusmata			2)Pinakes");
			scanf("%d",&subchoice);
		
			if(subchoice==1)//Epilogh provolhs twn diathesimwn dianusmatwn
			{
			   for(i=1;i<=plithosd;i++)
				{
				   	for(check=1;check<=dd;check++)//Elegxos gia to an kapoio apo ta dianusmata exei diagrafei
				 		if(i==deld[check])
				 		{
				 			if(i>1)
				 			 printf("\n");
				 			 
						 	printf("%do dianusma: Diagrammeno ",i);
						 	
						 	var=1;	
						}
				 		
						if(var==0)
						{
							printf("\n%do dianusma: [",i);
							for(j=0;j<stoixeia[i];j++)
					 			printf(" %.2f",dianusma[i][j]); 
							printf("]");
						}
						var=0;
				 }
				 
				
			}
			
			if(subchoice==2)//Epilogh provolhs twn diathesimwn pinakwn
				for(k=1;k<=plithosp;k++)
				{
					for(check=1;check<=dp;check++)//Elegxos gia to an kapoios apo tous pinakes exei diagrafei
					 	if(k==delp[check])
					 	{  
					 		if(k>1)
					 		 	printf("\n");
					 		 	
							printf("%dos pinakas: \n Diagrammenos",k);
							
							var=1;
						}
						
					if(var==0)
					{
											  						  
						printf("\n%dos pinakas: \n[%.2f\t",k,pinakas[k][0][0]);
						for(j=1;j<sthles[k];j++)
							printf("%.2f\t",pinakas[k][0][j]);
						if(grammes[k]==1)
							printf("]");
						else
						{
							printf("\n");
							for(i=1;i<grammes[k]-1;i++)
							{
								printf(" ");
								for(j=0;j<sthles[k];j++)
								 printf("%.2f\t",pinakas[k][i][j]);
						
								printf("\n") ;	
							}
						
							printf(" ");
							for(j=0;j<sthles[k]-1;j++)
								printf("%.2f\t",pinakas[k][grammes[k]-1][j]);
							printf("%.2f]",pinakas[k][grammes[k]-1][sthles[k]-1]);
						}
					}
					var=0;
				}
		 	
			printf("\n--------------------------------\n");
			system("pause");
			system("cls");			
	}
	
	if(choice==4)//Diagrafh sustoixias
	{
		system("cls");
		printf("Epithumeis na diagrapseis ena dianusma h enan pinaka? \n");
		printf("\n1)Dianusma			2)Pinakas");
		scanf("%d",&subchoice);
		
		if(subchoice==1)//Epilogh diagrafhs kapoiou dianusmatos
		{
			dd++;
			system("cls");
			
			printf("Poio dianusma epithumeis na diagrapseis?\n");
			scanf("%d",&deld[dd]);
			
			free(dianusma[deld[dd]]);//Diagrafh tou epilegmenou dianusmatos
			
		}
		
		if(subchoice==2)//Epilogh diagrafhs kapoiou pinaka
		{
			dp++;
			system("cls");
			
			printf("Poion pinaka epithumeis na diagrapseis?\n");
			scanf("%d",&delp[dp]);
			
			for(i=0;i<grammes[delp[dp]];i++)//Diagrafh tou epilegmenou pinaka
				 free(pinakas[delp[dp]][i]);
			free(pinakas[delp[dp]]);	
			 
			
		}
		
		printf("\n--------------------------------\n");
		system("pause");
		system("cls");
	}
	
	if(choice==5)//Pragmatopoihsh praxhs
	{
		system("cls");
		printf("Epithumeis na pragmatopoihseis praxh dianusmatwn h pinakwn?\n");
		printf("\n1)Dianusmata			2)Pinakes");
		scanf("%d",&subchoice);
		
		if(subchoice==1)//Epilogh pragmatopoihshs praxhs dianusmatwn
		{
			system("cls");
			
			printf("1)Prosthesh		2)Afairesh		3)Eswteriko ginomeno		4)Exwteriko ginomeno	\n5)Pollaplasiasmos me arithmo\n");
			scanf("%d",&praxh);//Epilogh praxhs
		
		
			
			if(praxh==1)//Prosthesh duo dianusmatwn
			{
				printf("\nEpelexe to prwto dianusma: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dd;check++)
					if(oros1==deld[check])//Elegxos gia to an to epilegmeno dianusma exei diagrafei
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros1);
						check=0;
					}
				
				printf("Epelexe to deutero dianusma: \n");
				scanf("%d",&oros2);
				for(check=1;check<=dd;check++)
					if(oros2==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros2);
						check=0;
					}
					
				if(stoixeia[oros1]!=stoixeia[oros2])
					printf("H prosthesh den mporei na pragmatopoihthei!");//Elegxos gia to an ta duo dianusmata exoun idio arithmo stoixeiwn
				else 
				{
					plithosd++;
					stoixeia[plithosd]=stoixeia[oros1];
					dianusma[plithosd]=(float *)malloc(sizeof(float)*stoixeia[plithosd]);
					for(i=0;i<stoixeia[plithosd];i++)
						dianusma[plithosd][i]=dianusma[oros1][i]+dianusma[oros2][i];
					
					printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
					printf("\n1)NAI				2)OXI\n");
					scanf("%d",&doc);
					
					if(doc==1)
						grapsimo_arxeiou_dianusma(&fp,dianusma[plithosd],stoixeia[plithosd]);
				}
		
			}
			
			if(praxh==2)//Afairesh duo dianusmatwn
			{
				printf("\nEpelexe to prwto dianusma: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dd;check++)
					if(oros1==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros1);
						check=0;
					}
				
				printf("Epelexe to deutero dianusma: \n");
				scanf("%d",&oros2);
				for(check=1;check<=dd;check++)
					if(oros2==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros2);
						check=0;
					}
					
				if(stoixeia[oros1]!=stoixeia[oros2])
					printf("H afairesh den mporei na pragmatopoihthei!");//Elegxos gia to an ta duo dianusmata exoun ton idio arithmo stoixeiwn
				else
				{
					plithosd++;
					stoixeia[plithosd]=stoixeia[oros1];
					dianusma[plithosd]=(float *)malloc(sizeof(float)*stoixeia[plithosd]);
					for(i=0;i<stoixeia[plithosd];i++)
						dianusma[plithosd][i]=dianusma[oros1][i]-dianusma[oros2][i];
						
					printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
					printf("\n1)NAI				2)OXI\n");
					scanf("%d",&doc);
					
					if(doc==1)
						grapsimo_arxeiou_dianusma(&fp,dianusma[plithosd],stoixeia[plithosd]);	
				}
			}
			
			if(praxh==3)//Ypologismos eswterikou ginomenou duo dianusmatwn
			{
					printf("\nEpelexe to prwto dianusma: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dd;check++)
					if(oros1==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros1);
						check=0;
					}
				
				printf("Epelexe to deutero dianusma: \n");
				scanf("%d",&oros2);
				for(check=1;check<=dd;check++)
					if(oros2==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros2);
						check=0;
					}
					
				if(stoixeia[oros1]!=stoixeia[oros2])
					printf("H praxh den mporei na pragmatopoihthei!");//Elegxos gia to an ta duo dianusmata exoun ton idio arithmo stoixeiwn
				else
				{
					sum=0;
					for(i=0;i<stoixeia[oros1];i++)
						sum=sum+dianusma[oros1][i]*dianusma[oros2][i];
					
					printf("Apotelesma: %.2f",sum);		
				}
				
				
			}
			
			if(praxh==4)//Ypologismos exwterikou ginomenou duo dianusmatwn
			{
				printf("\nEpelexe to prwto dianusma: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dd;check++)
					if(oros1==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros1);
						check=0;
					}
				
				printf("Epelexe to deutero dianusma: \n");
				scanf("%d",&oros2);
				for(check=1;check<=dd;check++)
					if(oros2==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros2);
						check=0;
					}
					
				if(stoixeia[oros1]!=3 || stoixeia[oros2]!=3)
					printf("H praxh den mporei na pragmatopoihthei!");//Elegxos gia ton an ta duo dianusmata exoun 3 akrivws stoixeia
				else
				{
					plithosd++;
					stoixeia[plithosd]=3;
					dianusma[plithosd]=(float *)malloc(sizeof(float)*3);
					
					dianusma[plithosd][0]=dianusma[oros1][1]*dianusma[oros2][2]-dianusma[oros1][2]*dianusma[oros2][1];
					dianusma[plithosd][1]=dianusma[oros1][2]*dianusma[oros2][0]-dianusma[oros1][0]*dianusma[oros2][2];
					dianusma[plithosd][2]=dianusma[oros1][0]*dianusma[oros2][1]-dianusma[oros1][1]*dianusma[oros2][0];
					
					printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
					printf("\n1)NAI				2)OXI\n");
					scanf("%d",&doc);
					
					if(doc==1)
						grapsimo_arxeiou_dianusma(&fp,dianusma[plithosd],stoixeia[plithosd]);
				}
			}
			
			if(praxh==5)//Pollaplasiasmos dianusmatos me arithmo
			{
				printf("\nEpelexe to dianusma: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dd;check++)
					if(oros1==deld[check])
					{
						printf("\nTo dianusma pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko dianusma: \n");
						scanf("%d",&oros1);
						check=0;
					}
					
				printf("Dwse ton arithmo: \n");
				scanf("%f",&arithmos);
				
				plithosd++;
				stoixeia[plithosd]=stoixeia[oros1];
				dianusma[plithosd]=(float *)malloc(sizeof(float)*stoixeia[plithosd]);
				for(i=0;i<stoixeia[plithosd];i++)
					dianusma[plithosd][i]=arithmos*dianusma[oros1][i];
					
				printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
				printf("\n1)NAI				2)OXI\n");
				scanf("%d",&doc);
					
				if(doc==1)
					grapsimo_arxeiou_dianusma(&fp,dianusma[plithosd],stoixeia[plithosd]);
			}
		}
		
		if(subchoice==2)//Epilogh pragmatopoishshs praxewn pinakwn
		{
			system("cls");
			
			printf("1)Prosthesh		2)Afairesh	3)Pollaplasiasmos 	4)Pollaplasiasmos me arithmo\n");
			scanf("%d",&praxh);//Epilogh praxhs
			
			if(praxh==1)//Prosthesh duo pinakwn
			{
				printf("\nEpelexe ton prwto pinaka: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dp;check++)
					if(oros1==delp[check])//Elegxos gia to an o epilegmenos pinakas exei diagrafei
					{
						printf("\nO pinakas pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko pinaka: \n");
						scanf("%d",&oros1);
						check=0;
					}
					
				printf("\nEpelexe ton deutero pinaka: \n");
				scanf("%d",&oros2);
				for(check=1;check<=dp;check++)
					if(oros2==delp[check])
					{
						printf("\nO pinakas pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko pinaka: \n");
						scanf("%d",&oros2);
						check=0;
					}
					
				if(grammes[oros1]!=grammes[oros2] || sthles[oros1]!=sthles[oros2])
					printf("\nH prosthesh den mporei na pragmatopoihthei!");//ELegxos gia to an oi duo pinakes exoun idio plithos grammwn kai sthlwn antistoixa
				else
				{
					plithosp++;
					grammes[plithosp]=grammes[oros1];
					sthles[plithosp]=sthles[oros1];
					
					pinakas[plithosp]=(float **)malloc(sizeof(float *)*grammes[plithosp]);
					if(!pinakas[plithosp])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
					for(i=0;i<grammes[plithosp];i++)
					{
						pinakas[plithosp][i]=(float *)malloc(sizeof(float)*sthles[plithosp]);
						if(!pinakas[plithosp][i])
						{
							printf("\nAdunamia desmeushs mnhmhs!");
							exit(0);
						}
					}
					
					for(i=0;i<grammes[plithosp];i++)
						for(j=0;j<sthles[plithosp];j++)
							pinakas[plithosp][i][j]=pinakas[oros1][i][j]+pinakas[oros2][i][j];
							
					printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
					printf("\n1)NAI				2)OXI\n");
					scanf("%d",&doc);
					
					if(doc==1)
						grapsimo_arxeiou_pinakas(&fp,pinakas[plithosp],grammes[plithosp],sthles[plithosp]);
				}
			}
			
			if(praxh==2)//Afairesh duo pinakwn
			{
				printf("\nEpelexe ton prwto pinaka: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dp;check++)
					if(oros1==delp[check])
					{
						printf("\nO pinakas pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko pinaka: \n");
						scanf("%d",&oros1);
						check=0;
					}
					
				printf("\nEpelexe ton deutero pinaka: \n");
				scanf("%d",&oros2);
				for(check=1;check<=dp;check++)
					if(oros2==delp[check])
					{
						printf("\nO pinakas pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko pinaka: \n");
						scanf("%d",&oros2);
						check=0;
					}
					
				if(grammes[oros1]!=grammes[oros2] || sthles[oros1]!=sthles[oros2])
					printf("\nH afairesh den mporei na pragmatopoihthei!");//ELegxos gia to an oi duo pinakes exoun idio plithos grammwn kai sthlwn antistoixa 
				else
				{
					plithosp++;
					grammes[plithosp]=grammes[oros1];
					sthles[plithosp]=sthles[oros1];
					
					pinakas[plithosp]=(float **)malloc(sizeof(float *)*grammes[plithosp]);
					if(!pinakas[plithosp])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
					for(i=0;i<grammes[plithosp];i++)
					{
						pinakas[plithosp][i]=(float *)malloc(sizeof(float)*sthles[plithosp]);
						if(!pinakas[plithosp][i])
						{
							printf("\nAdunamia desmeushs mnhmhs!");
							exit(0);
						}
					}
					
					for(i=0;i<grammes[plithosp];i++)
						for(j=0;j<sthles[plithosp];j++)
							pinakas[plithosp][i][j]=pinakas[oros1][i][j]-pinakas[oros2][i][j];
							
					printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
					printf("\n1)NAI				2)OXI\n");
					scanf("%d",&doc);
					
					if(doc==1)
						grapsimo_arxeiou_pinakas(&fp,pinakas[plithosp],grammes[plithosp],sthles[plithosp]);	
				}
			}
			
			if(praxh==3)//Pollaplasiasmos duo pinakwn
			{
				printf("\nEpelexe ton prwto pinaka: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dp;check++)
					if(oros1==delp[check])
					{
						printf("\nO pinakas pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko pinaka: \n");
						scanf("%d",&oros1);
						check=0;
					}
					
				printf("\nEpelexe ton deutero pinaka: \n");
				scanf("%d",&oros2);
				for(check=1;check<=dp;check++)
					if(oros2==delp[check])
					{
						printf("\nO pinakas pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko pinaka: \n");
						scanf("%d",&oros2);
						check=0;
					}
					
				if(sthles[oros1]!=grammes[oros2])
					printf("\nO pollaplasiasmos den mporei na pragmatopoihthei!");//ELegxos gia to an to plithos twn sthlwn tou prwtou pinaka einai iso me to plithos twn grammwn tou deuterou
				else
				{
					plithosp++;
					grammes[plithosp]=grammes[oros1];
					sthles[plithosp]=sthles[oros2];
					
					pinakas[plithosp]=(float **)malloc(sizeof(float *)*grammes[plithosp]);
					if(!pinakas[plithosp])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
					for(i=0;i<grammes[plithosp];i++)
					{
						pinakas[plithosp][i]=(float *)malloc(sizeof(float)*sthles[plithosp]);
						if(!pinakas[plithosp][i])
						{
							printf("\nAdunamia desmeushs mnhmhs!");
							exit(0);
						}
					}
					for(i=0;i<grammes[plithosp];i++)
						for(j=0;j<sthles[plithosp];j++)
						{
							sum=0;
							for(k=0;k<sthles[oros1];k++)
								sum=sum+pinakas[oros1][i][k]*pinakas[oros2][k][j];
							pinakas[plithosp][i][j]=sum;	
						}
						
					printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
					printf("\n1)NAI				2)OXI\n");
					scanf("%d",&doc);
					
					if(doc==1)
						grapsimo_arxeiou_pinakas(&fp,pinakas[plithosp],grammes[plithosp],sthles[plithosp]);
				}	
			}
			
			if(praxh==4)//Pollaplasiasmos pinaka me arithmo
			{
				printf("\nEpelexe ton pinaka: \n");
				scanf("%d",&oros1);
				for(check=1;check<=dp;check++)
					if(oros1==delp[check])
					{
						printf("\nO pinakas pou epelexes exei diagrafei!");
						printf("\nEpelexe diaforetiko pinaka: \n");
						scanf("%d",&oros1);
						check=0;
					}
					
				printf("Dwse ton arithmo: \n");
				scanf("%f",&arithmos);
			
				plithosp++;
				grammes[plithosp]=grammes[oros1];
				sthles[plithosp]=sthles[oros1];
				
				pinakas[plithosp]=(float **)malloc(sizeof(float *)*grammes[plithosp]);
				if(!pinakas[plithosp])
				{
					printf("\nAdunamia desmeushs mnhmhs!");
					exit(0);
				}
				for(i=0;i<grammes[plithosp];i++)
				{
					pinakas[plithosp][i]=(float *)malloc(sizeof(float)*sthles[plithosp]);
					if(!pinakas[plithosp][i])
					{
						printf("\nAdunamia desmeushs mnhmhs!");
						exit(0);
					}
				}
				
				for(i=0;i<grammes[plithosp];i++)
					for(j=0;j<sthles[plithosp];j++)
						pinakas[plithosp][i][j]=arithmos*pinakas[oros1][i][j];
						
				printf("\nEpithumeis na apothikeuseis ton neo pinaka se kapoio arxeio?");
				printf("\n1)NAI				2)OXI\n");
				scanf("%d",&doc);
					
				if(doc==1)
					grapsimo_arxeiou_pinakas(&fp,pinakas[plithosp],grammes[plithosp],sthles[plithosp]);			
			}
		}

		printf("\n--------------------------------\n");
		system("pause");
		system("cls");
	
	}
	
  }
  //Apeleutherwsh tou desmeumenou xwrou mnhmhs gia tis diafores sustoixies
  	for(i=1;i<=plithosd;i++)
  		free(dianusma[i]);
  		
  	
	for(i=1;i<=plithosp;i++)
		for(j=0;j<grammes[i];j++)
			free(pinakas[i][j]);
	for(i=1;i<=plithosp;i++)
		free(pinakas[i]);	
}


void katalogos(int *a)
{
		printf("----------------EPILOGES------------------");
		printf("\n1)Dhmiourgia sustoixias");
		printf("\n2)Fortwsh sustoixias apo arxeio");
		printf("\n3)Provolh diathesimwn sustoixiwn");
		printf("\n4)Diagrafh kapoias apo tis diathesimes sustoixies");
		printf("\n5)Pragmatopoihsh praxhs");
		printf("\nGIA EXODO PATHSE TO 0.\n");
		scanf("%d",&(*a));
}


void dhmiourgia_dianusmatos(float *vector,int stoixeia)
{			
			
			int i;
			system("cls");
		
			printf("\nOrismos timwn stoixeiwn");
			for(i=0;i<stoixeia;i++)
			{
				printf("\n%do stoixeio: ",i+1);
				scanf("%f",&vector[i]);
			}
}


void dhmiourgia_pinaka(float **array,int grammes,int sthles)
{
	int i,j;
	system("cls");
	
	printf("\nOrismos timwn stoixeiwn\n ");
	for(i=0;i<grammes;i++)
	 for(j=0;j<sthles;j++)
	 {
	 	printf("Stoixeio %d %d: ",i+1,j+1);
	 	scanf("%f",&array[i][j]);
	 }
}

void grapsimo_arxeiou_dianusma(FILE **f,float *array,int plithos)
{
	int check1,i;
	char arxeio[SIZE];
	printf("\nDwse to arxeio sto opoio tha ginei h apothikeush: \n");
	scanf("%s",arxeio);
	*f=fopen(arxeio,"a+b");
	
	check1=fwrite(array,sizeof(float),plithos,*f);
	if(check1!=plithos)	
		printf("Adunamia apothikeushs sto arxeio!");
		
	fclose(*f);	
}

void grapsimo_arxeiou_pinakas(FILE **f,float **array,int rows,int columns)
{
	int check1,i;
	char arxeio[SIZE];
	printf("\nDwse to arxeio sto opoio tha ginei h apothikeush: \n");
	scanf("%s",arxeio);
	*f=fopen(arxeio,"a+b");
	
	for(i=0;i<rows;i++)
	{	
		check1=fwrite(array[i],sizeof(float),columns,*f);
		if(check1!=columns)	
		{
			printf("Adunamia apothikeushs sto arxeio!");
			break;
		}
	}
		
		fclose(*f);
			
}
