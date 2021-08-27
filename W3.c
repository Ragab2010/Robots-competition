/*
 * main.c
 *	Creator - VIjaypal Singh
 *  Studnet no. - 10418871
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>    // time()



//this structure holds robot's information
typedef  struct robot{
	unsigned int Robot_Number ;
	char Robot_Name[60];
	unsigned int Year_Manufactured ;
	float Top_Speed ;
	float mass;
	float Best_score;
	unsigned int stateOfTest;
}Robot;


typedef  struct robotres{
	unsigned int Robot_Number ;
	char Robot_Name[60];
	unsigned int Year_Manufactured ;
	float Top_Speed ;
	float mass;
	float Best_score;
	unsigned int stateOfTest;
	float finish_line_distance;
	float finish_line_time;
	float strength;
	int combat_effectiveness;
	int order;
	int order_flage;


}RobotResult;

int numOfRobot=0;//number of all robots
int numOfRobotForComp;//number of competition robots only
int numOfRobotResult=0;
int orderofresult[50];

// gloable variable for distance , finish_time , Trial_speed
float distance=0.0,finish_time=0.0,Trial_speed=0.0 , strength =0.0  ;
int score=0 ,combat_effectiveness =0;


//prototype
void initializeRoboticsCompetition(Robot *p , FILE *pfile);
void printListRobots(struct robot *p);
float calculateTrial_speed(float finish_line_distance, float finish_line_time);
int printRobotComptetion(float Trial_speed , struct robot * p );
float calculateTrialSpeed(struct robot *p);
void searchingRobotInformation(struct robot *p);
float min(float n1, float n2);
void calculate_combat(struct robot *pf  ,struct robotres*pr );
int calculate_strength();
void print_Robot_Test_Simulation_Result (struct robot *p  , struct robotres*pr, int i ,  float best_score);
void Display_simulation_results(struct robot *p , struct robotres *pr);
void Save_robot_information(struct robot *p ,FILE *pfile , int numberOfRobots);
void menu(struct robot *p   ,struct robotres*pr, FILE *pfile_Robot , FILE *pfile_Result );
void Save_all_results(struct robotres *pr , FILE *pfile_Result);
void Display_winners(struct robot *p , struct robotres *pr);
void Exit(FILE *pfile_Robot , FILE *pfile_Result);
void fun_sel(struct robotres *pr );

//this function to store the list of robot information
void initializeRoboticsCompetition(Robot *p , FILE *pfile){
	//now we enter the list information the five robots
//		p[0].Robot_Number=1;
//		strcpy(p[0].Robot_Name,"AdamTheLink");
//		p[0].Year_Manufactured =1999;
//		p[0].Top_Speed =15.0;
//		p[0].mass=110;
//		p[0].Best_score=0.0;
//		p[0].stateOfTest=0;
//
//		p[1].Robot_Number=2;
//		strcpy(p[1].Robot_Name,"BrainAT");
//		p[1].Year_Manufactured =2010;
//		p[1].Top_Speed =32.5;
//		p[1].mass=18;
//		p[1].Best_score=0.0;
//		p[1].stateOfTest=0;
//
//		p[2].Robot_Number=3;
//		strcpy(p[2].Robot_Name,"BOBBY");
//		p[2].Year_Manufactured =2013;
//		p[2].Top_Speed =29.5;
//		p[2].mass=7.5;
//		p[2].Best_score=0.0;
//		p[2].stateOfTest=0;
//
//
//		p[3].Robot_Number=4;
//		strcpy(p[3].Robot_Name,"MiMi");
//		p[3].Year_Manufactured =2018;
//		p[3].Top_Speed =40.0;
//		p[3].mass=8.8;
//		p[3].Best_score=0.0;
//		p[3].stateOfTest=0;
//
//		p[4].Robot_Number=5;
//		strcpy(p[4].Robot_Name,"myMewRobot");
//		p[4].Year_Manufactured =2019;
//		p[4].Top_Speed =40.0;
//		p[4].mass=70.0;
//		p[4].Best_score=0.0;
//		p[4].stateOfTest=0;

//		numOfRobot=5;
//		Save_robot_information(p , pfile , numOfRobot);

		for (int i = 0; !feof(pfile); ++i) {
			fscanf(pfile ,"%u\t%s\t%u\t%f\t%f\t%f\n" , &p[i].Robot_Number ,p[i].Robot_Name,&p[i].Year_Manufactured , &p[i].Top_Speed, &p[i].mass , &p[i].Best_score);
			numOfRobot++;
		}
		for (int i = 0; i < numOfRobot; ++i) {
			printf("%u\t%10s\t%16u\t%15f\t%7f\t%7f\n" , p[i].Robot_Number ,p[i].Robot_Name,p[i].Year_Manufactured , p[i].Top_Speed, p[i].mass , p[i].Best_score);
		}
		printf("Number of Robots is =%d\n" , numOfRobot);

}

//function to print on screen list of robots that could be used for the robotics competition
void printListRobots(struct robot *p){
	printf("The following is the list of robots that could be used for the robotics competition\n\n");
	printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg)\n");
	for (int i = 0; i < 5; ++i) {
		printf("%12d | ", p[i].Robot_Number);
		printf("%10s | ", p[i].Robot_Name);
		printf("%16d  | ", p[i].Year_Manufactured);
		printf("%14.2f | ", p[i].Top_Speed);
		printf("%6.2f | \n", p[i].mass);
	}
}

int printRobotComptetionAll(struct robot * p ){
	unsigned int count=0 ;
	int choosing_robot=0;
	printf("The following is the list Robots capable of being used for a robotics competition with Trial_speed of <%f> (m/s):\n", Trial_speed);
	printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg) |Best_score\n");
	for (int i = 0 , j=0; i<numOfRobot; ++i) {
		//check if the robot's top speed greate tan or equal Trial_speed
			//if robot has  top speed greate tan or equal Trial_speed , so print all information

			printf("%12d | ", p[i].Robot_Number);
			printf("%10s | ", p[i].Robot_Name);
			printf("%16d  | ", p[i].Year_Manufactured);
			printf("%15f | ", p[i].Top_Speed);
			printf("%7f | ", p[i].mass);
			printf("%7f | \n", p[i].Best_score);
			count++;//count number of robot which can compete
			j++;


	}

	//if there's no robot's can compete - print there  are no robot which can do this competition else print number of robots

	printf("please Type the number of Robot to do competetion :");
	scanf("%d",&choosing_robot );
	while((choosing_robot > numOfRobot)||(choosing_robot< 1)){

		printf("You have Enter Wrong Number\nplease Type the number of Robot to do competetion :");
	scanf("%d",&choosing_robot );
	}
	return choosing_robot;
}

//function to print on screen list Robots capable of being used for a robotics competition
int printRobotComptetion(float Trial_speed , struct robot * p ){
	unsigned int count=0 ;
	int choosing_robot=0;
	printf("The following is the list Robots capable of being used for a robotics competition with Trial_speed of <%f> (m/s):\n", Trial_speed);
	printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg)\n");
	for (int i = 0 , j=0; i<numOfRobot; ++i) {
		//check if the robot's top speed greate tan or equal Trial_speed
		if((int)p[i].Top_Speed >= (int)Trial_speed  ){
			//if robot has  top speed greate tan or equal Trial_speed , so print all information
			printf("%12d | ", p[i].Robot_Number);
			printf("%10s | ", p[i].Robot_Name);
			printf("%16d  | ", p[i].Year_Manufactured);
			printf("%14.2f | ", p[i].Top_Speed);
			printf("%6.2f | \n", p[i].mass);
			p[j].Robot_Number=p[i].Robot_Number;
			strcpy(p[j].Robot_Name,p[i].Robot_Name);
			p[j].Year_Manufactured =p[i].Year_Manufactured;
			p[j].Top_Speed =p[i].Top_Speed;
			p[j].mass=p[i].mass;
			count++;//count number of robot which can compete
			j++;
		}


	}
	numOfRobotForComp=count;//assign number  of robot which can compete
	//if there's no robot's can compete - print there  are no robot which can do this competition else print number of robots
	if(count ==0){
		printf("\nThere is no robot which can do this competition\n");
		return -1;
	}else{
		printf("A total of %d robots are capable of being used for the robotics competition scenario\n" , count);
	}
	printf("please Type the number of Robot to do competetion :");
	do{
		printf("You have Enter Wrong Number\nplease Type the number of Robot to do competetion :");
	scanf("%d",&choosing_robot );
	}while(choosing_robot >= numOfRobot);
	return choosing_robot;
}

//this function calculate the speed and return the speed in floating point numbers
float calculateTrial_speed(float finish_line_distance, float finish_line_time){
	//divide distance by time to calculate the speed
	float robot_Speed=finish_line_distance/finish_line_time;
	//print Trial_speed
	printf("Trial_speed =%f\n" , robot_Speed);
	//return the final speed
	return robot_Speed;
}


//function to show the competition
float calculateTrialSpeed(struct robot *p){
	char str[20];
	printf(" \n");
    //taking distance input from the user
    printf("Please input the distance in meters to the finish line\n");//fflush(NULL);
    scanf("%s", str);
    distance =atof(str);
    //if user enter wrong distance , will ask user again and again while write right number
    while(distance ==0 || distance <0){
	    printf("You Have entered wrong number!!\nPlease input the distance in meters to the finish line\n");
	    scanf("%s", str);
	    distance =atof(str);
    }

    //taking time from user as input
     printf("Please input the finish time of the robot in seconds\n");//fflush(NULL);
     scanf("%s", str);
     finish_time=atof(str);
     //if user enter wrong finish , will ask user again and again while write right number
     while(finish_time ==0 || finish_time <0){
         printf("You have entered wrong number!!\nPlease input the finish time of the robot in seconds\n");
         scanf("%s", str);
         finish_time=atof(str);
     }
     //calling the function that calculate the speed and return it and store it in speed variable
     Trial_speed=calculateTrial_speed(distance,finish_time);
     return Trial_speed;



}

/*------------------------------------------------------------------------------------*/
//function searching Robot Information
void searchingRobotInformation(struct robot *p){
	char name[60];
	int flage=0;
	//ask about name of robot
	printf("Enter the Robot name\n");
	scanf("%s" , name);
	//here loop on all the list and test the name
	if(strcasecmp(name , "ALL" ) ==0 ){
		printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg)\n |Best_score\n");
		for (int i = 0; i < numOfRobot; ++i) {
				//if the name equal so print all information
				printf("%12d | ", p[i].Robot_Number);
				printf("%10s | ", p[i].Robot_Name);
				printf("%16d  | ", p[i].Year_Manufactured);
				printf("%15f | ", p[i].Top_Speed);
				printf("%7f | ", p[i].mass);
				printf("%7f | \n", p[i].Best_score);
				flage =1;// assign 1 to flag because there's robot in list by this name
		}
	}else{
		printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg)\n |Best_score\n");
		for (int i = 0; i < numOfRobot; ++i) {
			if(strcasecmp(name , p[i].Robot_Name) ==0){
				//if the name equal so print all information
				printf("%12d | ", p[i].Robot_Number);
				printf("%10s | ", p[i].Robot_Name);
				printf("%16d  | ", p[i].Year_Manufactured);
				printf("%15f | ", p[i].Top_Speed);
				printf("%7f | ", p[i].mass);
				printf("%7f | \n", p[i].Best_score);
				flage =1;// assign 1 to flag because there's robot in list by this name
				break;
			}
		}
	}

	//flage to now if there's robot by this name
	if(flage ==0){
		printf("there no robot by this Name.\n");
	}
}


void addRobotsToList(struct robot *p ){
	int robotNumber =0;
	char str[20];

	printf("-------------------------------------------------------");
	printf("\nRobot_Number= ");//fflush(NULL);
	scanf("%s", str);
	robotNumber=atof(str);
	while((robotNumber <1 ) ||(robotNumber >50)){
		printf("\nyou have Enter wrong number please\nRobot_Number= ");//fflush(NULL);
		scanf("%d", &robotNumber);
	}
	if(robotNumber < numOfRobot){
		robotNumber--;
		printf("The robot is exist !.\n");
		p[robotNumber].Robot_Number=robotNumber+1;
		printf("Robot_Name= ");//fflush(NULL);
		scanf("%s", p[robotNumber].Robot_Name);
		printf("Year_Manufactured= ");//fflush(NULL);
		scanf("%d",&p[robotNumber].Year_Manufactured);
		printf("Top_Speed= ");//fflush(NULL);
		scanf("%f", &p[robotNumber].Top_Speed);
		printf("mass= ");//fflush(NULL);
		scanf("%f", &p[robotNumber].mass);
		printf("Best_score= ");//fflush(NULL);
		scanf("%f", &p[robotNumber].Best_score);
	}else{
		//	printf("\nRobot_Number= ");//fflush(NULL);
		//	scanf("%d", &p[robotNumber].Robot_Number);
		printf("The robot is not exist . so it will be Robot number %d  .\n" ,numOfRobot+1 );
			robotNumber =numOfRobot;
			p[robotNumber].Robot_Number=numOfRobot+1;
			printf("Robot_Name= ");//fflush(NULL);
			scanf("%s", p[robotNumber].Robot_Name);
			printf("Year_Manufactured= ");//fflush(NULL);
			scanf("%d",&p[robotNumber].Year_Manufactured);
			printf("Top_Speed= ");//fflush(NULL);
			scanf("%f", &p[robotNumber].Top_Speed);
			printf("mass= ");//fflush(NULL);
			scanf("%f", &p[robotNumber].mass);
			printf("Best_score= ");//fflush(NULL);
			scanf("%f", &p[robotNumber].Best_score);
			numOfRobot++;//variable to count the number of new robots

		}


}



//this function take the strength of robot and return it;
int calculate_strength(){
	int number_of_objects;

	//taking number from user between 1 and 100
	printf("Please input the number of objects the robot can lift (between 1 and 100)\n");
    scanf("%d", &number_of_objects);

    //checking that the number is between 1-100
    if(number_of_objects<1 || number_of_objects> 100){
    	//if not number betweeen 1-100 it will take again number from user until it enter correct number
    	while(1){
			printf("Error!  the number of objects the robot  that can lift Must between 1 and 100\n");
    		scanf("%d", &number_of_objects);
//    		if(number_of_objects>=1 && number_of_objects<= 100){
//    			break;
//			}
		}
	}


    //retrn the strength
    return number_of_objects;
}

//this function take two float parameters and return the minimum value from both of them
float min(float n1, float n2){
	if(n1>n2){
		//if number2 is smaller then it return n2
		return n2;
	}else{
		//if number 1 is smaller then itreturn 21
		return n1;
	}
}
//function to print the result of simulation test
void print_Robot_Test_Simulation_Result (struct robot *p ,  struct robotres*pr ,int i , float best_score){
	printf("Robot Test/Simulation Result \n\n");
	printf("Robot information:\n");
	printf("Robot_Number  \t%d\n", p[i].Robot_Number);
	printf("Robot_Name    \t%s\n", p[i].Robot_Name);
	printf("Year_Manufac  \t%d\n", p[i].Year_Manufactured);
	printf("Top_Speed(m/s)\t%f\n", p[i].Top_Speed);
	printf("Mass(kg)      \t%f\n", p[i].mass);
	printf("Best_score    \t%f\n", p[i].Best_score);

	printf("Test conditions: \n");

	printf("finish_line_distance  \t%f\n", distance);
	printf("finish_line_time      \t%f\n", finish_time);
	printf("strength              \t%f\n", strength);

	printf("Simulation result: \n");

	printf("combat_effectiveness  \t%d\n", combat_effectiveness );
	/***********************stor the result in struct *****************************/
	pr[numOfRobotResult].Robot_Number=p[i].Robot_Number;
	strcpy(pr[numOfRobotResult].Robot_Name , p[i].Robot_Name);
	pr[numOfRobotResult].Year_Manufactured=p[i].Year_Manufactured;
	pr[numOfRobotResult].Top_Speed=p[i].Top_Speed;
	pr[numOfRobotResult].mass=p[i].mass;
	pr[numOfRobotResult].Best_score=best_score;

	pr[numOfRobotResult].finish_line_distance=distance;
	pr[numOfRobotResult].finish_line_time=finish_time;
	pr[numOfRobotResult].strength=strength;
	pr[numOfRobotResult].combat_effectiveness=combat_effectiveness;
	numOfRobotResult++;



}


//function to do calculate_combat and simulation test
void calculate_combat(struct robot *pf  ,struct robotres* pr  ){
	int robotNumber , flage_score=0 , score=0;
	float low_percentage =0.0,high_percentage=0.0 , test=0.0;
	robotNumber =printRobotComptetionAll( pf);
	robotNumber--;
	Trial_speed=calculateTrialSpeed(pf);
	strength =calculate_strength();
	pf[robotNumber].stateOfTest=1;//flage that robot will make simulation or Test

	/*********************combat_effectiveness********************************/
	low_percentage = (min(Trial_speed , 50)+ ((strength/100)* 50)-10);
	high_percentage = (min(Trial_speed , 50)+ ((strength/100)* 50)+10);
	printf("This roboot has a %f -- %f %%  chance of winning against a human\nStarting combat\n" , low_percentage ,high_percentage);
	for (int j = 0; j < 100; ++j) {
		test = (min(Trial_speed , 50)+ ((strength/100)* 50)-(rand() %((10 + 10 + 1)) -10));
		printf("simulate with Random number=%d and Test is=%f\n" , (rand() %((10 + 10 + 1)) -10) , test);
    	if(test>= low_percentage && test<=high_percentage){
    		printf("robot has won!\n");
    		score++;
		}else{
			printf("robot has lost!\n");
		}
	}
	printf("After Fighting 100 humans, the robot won: %d time\n" , score);
	combat_effectiveness =score;
	/*******************************/
	//now write teh score into Best_score field  of Robot
	if(score > pf[robotNumber].Best_score){
		printf("do you whant write  Score in Best_score field  of Robot:\n1-Yes\n2-No\n");
		scanf("%d" ,&flage_score);
		while((flage_score !=1)&&(flage_score !=2)){
			printf("you Have Enter wrong Numberpleas\ndo you whant write  Score in Best_score field  of Robot:\n1-Yes\n2-No\n");
			scanf("%d" ,&flage_score);
		}
		pf[robotNumber].Best_score =score;
	}
	print_Robot_Test_Simulation_Result(pf   , pr, robotNumber , score);


}








//function  for Display_simulation_results
void Display_simulation_results(struct robot *p ,struct robotres *pr){
	char name[60];
	int flage=0;
	//ask about name of robot
	printf("Enter the Robot name\n");
	scanf("%s" , name);
	//here loop on all the list and test the name
	printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg) |Best_score\n");
	if(strcasecmp(name , "ALL" ) ==0 ){
		for (int i = 0; i < numOfRobot; ++i) {
			if(p[i].stateOfTest==1){
				printf("%12d | ", p[i].Robot_Number);
				printf("%10s | ", p[i].Robot_Name);
				printf("%16d  | ", p[i].Year_Manufactured);
				printf("%15f | ", p[i].Top_Speed);
				printf("%7f | ", p[i].mass);
				printf("%7f | \n", p[i].Best_score);
				flage =1;// assign 1 to flag because there's robot in list by this name
			}

		}
	}else{
		for (int i = 0; i < numOfRobot; ++i) {
			if(!strcasecmp(name , p[i].Robot_Name)){
				if(p[i].stateOfTest==1){
					printf("%12d | ", p[i].Robot_Number);
					printf("%10s | ", p[i].Robot_Name);
					printf("%16d  | ", p[i].Year_Manufactured);
					printf("%15f | ", p[i].Top_Speed);
					printf("%7f | ", p[i].mass);
					printf("%7f | \n", p[i].Best_score);
					flage =1;// assign 1 to flag because there's robot in list by this name
					//break;
				}else{
					printf("%sd didn't tested yet\n ", p[i].Robot_Name);
					flage=1;
					//break;
				}
			}
		}
	}

	//flage to now if there's robot by this name
	if(flage ==0){
		printf("\n\nthere no robot by this Name Or there No Robot testing .\n\n");
	}
}


void fun_sel(struct robotres *pr ){
	int index=0 , flage;
	char char_swap[40];
	float float_swap , int_swap;
	for(int x=0; x<numOfRobotResult; x++){
			int index_of_max_top_speed = x;
			flage =0;
			for(int y=x+1; y<numOfRobotResult; y++){

				if((pr[y].Top_Speed >= pr[index_of_max_top_speed].Top_Speed)  ){

					index_of_max_top_speed = y;
					flage =1;
				}

			}
			orderofresult[index++]=index_of_max_top_speed;
			pr[index_of_max_top_speed].order_flage=1;

			/*******swap*******/
			int_swap = pr[index_of_max_top_speed].Robot_Number;
			pr[index_of_max_top_speed].Robot_Number =pr[x].Robot_Number;
			pr[x].Robot_Number=int_swap;
			/*************************/
			strcpy( char_swap , pr[index_of_max_top_speed].Robot_Name);
			strcpy( pr[index_of_max_top_speed].Robot_Name , pr[x].Robot_Name);
			strcpy(  pr[x].Robot_Name , char_swap);
			/**************************/
			float_swap = pr[index_of_max_top_speed].Top_Speed;
			pr[index_of_max_top_speed].Top_Speed =pr[x].Top_Speed;
			pr[x].Top_Speed=float_swap;

			/**************************/
			int_swap = pr[index_of_max_top_speed].Year_Manufactured;
			pr[index_of_max_top_speed].Year_Manufactured =pr[x].Year_Manufactured;
			pr[x].Year_Manufactured=int_swap;
			/**************************/
			int_swap = pr[index_of_max_top_speed].combat_effectiveness;
			pr[index_of_max_top_speed].combat_effectiveness =pr[x].combat_effectiveness;
			pr[x].combat_effectiveness=int_swap;
			/**************************/
			float_swap = pr[index_of_max_top_speed].finish_line_distance;
			pr[index_of_max_top_speed].finish_line_distance =pr[x].finish_line_distance;
			pr[x].finish_line_distance=float_swap;

			/**************************/
			float_swap = pr[index_of_max_top_speed].finish_line_time;
			pr[index_of_max_top_speed].finish_line_time =pr[x].finish_line_time;
			pr[x].finish_line_time=float_swap;

			/**************************/
			float_swap = pr[index_of_max_top_speed].mass;
			pr[index_of_max_top_speed].mass =pr[x].mass;
			pr[x].mass=float_swap;

			/**************************/
			float_swap = pr[index_of_max_top_speed].strength;
			pr[index_of_max_top_speed].strength =pr[x].strength;
			pr[x].strength=float_swap;


			if(flage==0){
				return ;
			}

			}

}

//fuction to display the winners if there winners
void Display_winners(struct robot *p , struct robotres *pr){

	if(numOfRobotResult == 0){
		printf("\n\nError there no robot has tested .\n\n");
		return ;
	}
	else if(numOfRobotResult >1){
		fun_sel(pr);
	}
	printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg) | Best_score\n");
	for (int i = 0; i < numOfRobotResult; ++i) {
		printf("%12d | ", pr[i].Robot_Number);
		printf("%10s | ", pr[i].Robot_Name);
		printf("%16d  | ", pr[i].Year_Manufactured);
		printf("%15f | ",pr[i].Top_Speed);
		printf("%7f | ", pr[i].mass);
		printf("%7f | \n",pr[i].Best_score);

	}


//	for (int i = 0; i < numOfRobot; ++i) {
//		if(p[i].stateOfTest==1){
//			flage =1;// assign 1 to flag because there's robot in list by this name
//
//		}
//
//	}
//	if(flage ==0){
//		printf("\n\nError there no robot has tested .\n\n");
//		return ;
//	}
//	printf("Robot_Number | Robot_Name | Year_Manufactured | Top_Speed(m/s) | Mass(kg) |Best_score\n");
//	for(int i = 0; i < numOfRobot; ++i){
//		if((p[i].stateOfTest==1 )&& (flage ==1) ){
//
//			printf("%12d | ", p[i].Robot_Number);
//			printf("%10s | ", p[i].Robot_Name);
//			printf("%16d  | ", p[i].Year_Manufactured);
//			printf("%15f | ", p[i].Top_Speed);
//			printf("%7f | ", p[i].mass);
//			printf("%7f | \n", p[i].Best_score);
//			flage =1;// assign 1 to flag because there's robot in list by this name
//		}
//	}
	printf("\n\nThe Robots Infromation has written.\n\n");
}

//function to save robots infromation into robot.txt file
void Save_robot_information(struct robot *p ,FILE *pfile_Robot , int numberOfRobots){
	int i;
	fseek(pfile_Robot , 0L ,SEEK_SET);

	for(i=0 ; i<numOfRobot ; i++){
		//printf("%u\t%10s\t%16u\t%15f\t%7f\t%7f\n" , p[i].Robot_Number ,p[i].Robot_Name,p[i].Year_Manufactured , p[i].Top_Speed, p[i].mass , p[i].Best_score);
		fprintf(pfile_Robot ,"%u\t%10s\t%16u\t%15f\t%7f\t%7f\n" , p[i].Robot_Number ,p[i].Robot_Name,p[i].Year_Manufactured , p[i].Top_Speed, p[i].mass , p[i].Best_score);
	}
	printf("\n\nThe Robots Infromation has written.\n\n");
}




//function to save all the results  in Result.txt file
void Save_all_results(struct robotres *pr , FILE *pfile_Result){

	fseek(pfile_Result , 0L ,SEEK_SET);
	if(numOfRobotResult == 0){
		printf("\n\nThe Robots Infromation has written.\n\n");
		fprintf(pfile_Result,"There is no Robots has tested \n\n");
		return ;
	}
	else if(numOfRobotResult >1){
		for(int i = 0; i < numOfRobotResult; ++i){
			fprintf(pfile_Result,"Robot Test/Simulation Result \n\n");
			fprintf(pfile_Result,"Robot information:\n");
			fprintf(pfile_Result,"Robot_Number  \t%d\n", pr[i].Robot_Number);
			fprintf(pfile_Result,"Robot_Name    \t%s\n", pr[i].Robot_Name);
			fprintf(pfile_Result,"Year_Manufac  \t%d\n", pr[i].Year_Manufactured);
			fprintf(pfile_Result,"Top_Speed(m/s)\t%f\n", pr[i].Top_Speed);
			fprintf(pfile_Result,"Mass(kg)      \t%f\n", pr[i].mass);
			fprintf(pfile_Result,"Best_score    \t%f\n", pr[i].Best_score);

			fprintf(pfile_Result,"Test conditions: \n");

			fprintf(pfile_Result,"finish_line_distance  \t%f\n", pr[i].finish_line_distance);
			fprintf(pfile_Result,"finish_line_time      \t%f\n",  pr[i].finish_line_time);
			fprintf(pfile_Result,"strength              \t%f\n", pr[i].strength);

			fprintf(pfile_Result,"Simulation result: \n");

			fprintf(pfile_Result,"combat_effectiveness  \t%d\n", pr[i].combat_effectiveness );
			fprintf(pfile_Result ,"-------------------------------------------------------------------------------");


			}
	}

	printf("\n\nThe Robots Infromation has written.\n\n");

}


//function to Exit from program
void Exit(FILE *pfile_Robot , FILE *pfile_Result){
	fclose(pfile_Robot);
	fclose(pfile_Result);
	exit(EXIT_SUCCESS);

}

void menu( struct robot *p    , struct robotres*pr, FILE *pfile_Robot , FILE *pfile_Result ){
	int choice=0;
	//print all option
	printf("Menu\n");
	printf("1-Search a robot .\n");
	printf("2-Input/update robot information.\n");
	printf("3-Simulate a robot against a human opponent.\n");//fflush(NULL);
	printf("4-Display simulation results.\n");
	printf("5-Display winners.\n");
	printf("6-Save robot information.\n");
	printf("7-Save all results.\n");
	printf("8-Exit.\n");
	printf("Please Enter the number:");
	scanf("%d" , &choice);
	//if the user enter number out from Menu , so will ask again to write right number
	while((choice > 8)&&(choice <1)){
		printf("1-Search a robot .\n");
		printf("2-Input/update robot information.\n");
		printf("3-Simulate a robot against a human opponent.\n");//fflush(NULL);
		printf("4-Display simulation results.\n");
		printf("5-Display winners.\n");
		printf("6-Save robot information.\n");
		printf("7-Save all results.\n");
		printf("8-Exit.\n");
		printf("Please Enter the number:");
		scanf("%d" , &choice);
	}

	//after you choice the number
	switch (choice) {
		//if you want to search about robots into list , call searchingRobotInformation() function to do this
		case 1:searchingRobotInformation(p);break;
		//if you want to input/update robot , call addRobotsToList() function
		case 2:addRobotsToList(p);break;
		//if you want to Simulate a robot against a human opponent  , call calculate_combat() function
		case 3:calculate_combat(p , pr);break;
		//if you want to Display_simulation_results  , call Display_simulation_results() function
		case 4:Display_simulation_results(p , pr);break;
		//if you want to Display_winners  , call Display_winners() function
		case 5:Display_winners(p , pr);break;
		//if you want to Save_robot_information  , call Save_robot_information() function
		case 6:Save_robot_information(p ,pfile_Robot , numOfRobot );break;
		//if you want to Save_all_results  , call Save_all_results() function
		case 7:Save_all_results(pr , pfile_Result);break;
		//if you want to Exit from program  , call Exit() function
		case 8:Exit(pfile_Robot , pfile_Result);break;




	}


}



void test(	FILE * file_Robot ,Robot *p ){
	for (int i = 0; i < numOfRobot; ++i) {
		fscanf(file_Robot ,"%u\t%s\t%u\t%f\t%f\t%f\n" , &p[i].Robot_Number ,p[i].Robot_Name,&p[i].Year_Manufactured , &p[i].Top_Speed, &p[i].mass , &p[i].Best_score);
	}
	for (int i = 0; i < numOfRobot; ++i) {
		printf("%u\t%10s\t%16u\t%15f\t%7f\t%7f\n" , p[i].Robot_Number ,p[i].Robot_Name,p[i].Year_Manufactured , p[i].Top_Speed, p[i].mass , p[i].Best_score);
	}

}
int main(){
	//setvbuf(stdout , NULL  , _IONBF , 0);
	//create array of Robot
	Robot Robot_info[50];
	RobotResult Robot_result[50];
	//open file with name Robot.txt /or create it if didn't exist
	FILE * file_Robot =fopen("Robot.txt" , "r+");
	//open file with name Result.txt /or create it if didn't exist
	FILE * file_Result =fopen("Result.txt" , "w");

	//initialize array of Robot and write Robots information into Robot.txt
	initializeRoboticsCompetition(Robot_info ,file_Robot );

//	//test(file_Robot , Robot_info);
//	calculate_combat(Robot_info);
	while(1){//do this forever
//
//		//show the Menu and the choose feture
		menu(Robot_info , Robot_result , file_Robot  , file_Result);

//
	}

	return 0;


}

