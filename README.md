# simulation-of-a-robotics-competition
 see files  (Work.docx ,  Updates required 3.docx , FLOWCHART.png)
 
 -----------------------------------------------------------------------
Your task is  creation of the simulation of a robotics competition.  
 
 The competition consists of three phases. 
1.Speed. The robots will race to reach the finish line. 
2.Strength. The robots will attempt to lift several heavy objects. 
3.Combat effectiveness. The robots will battle against 100 humans and then receive a score based on the number of victories. 
 
Design and implement the following:  
 
(1)Create a Robot struct with the following fields: 
•Robot_Number 
•Robot_Name 
•Year_Manufactured  
•Top_Speed 
•Mass 
 
Consider the following list of robots that could possibly be used in simulation of a robotics competition. 
 
            Table 1: List of robot information 
 
Robot 
Number 	 
Robot Name  
 	 
Year 
Manufactured  
 	 
Top Speed 
(m/s)  	 
Mass  
(kg) 
1 	AdamTheLink 	1999  	15  	110 
2 	BrainAT  	2010 	32.5 	18 
3 	BOBBY 	2013 	29.5 	7.5 
4 	MiMi 	2018 	40.0 	8.8 
 	… 	… 	 	 
 
 
(2)Extend your previous program provided to simulate the robotics competition using the robot information stored in the Robot_info array.   
 
Your program should first create an array of structs, Robot_info [ ], that stores robot information (using above defined struct, Robot).
 Your array should be able to store information for up to 50 robots. Initialize the Robot_info array with appropriate robot information for at least 5 robots. The program then displays all available robot information (with a properly designed format) on the screen.
 
 
 Updates required
1.When you first run the .exe file you can only see first five results from the robot.txt file. If there are more then 5 entries they would not be shown. 
	If there are less then 5 entries, it shows weird numbers

In this screenshot you can see, I only had two entries in robot.txt file and it auto-generated these weird numbers. Please fix this issue, it should show all the entries in txt file. When you run the .exe file without robot.txt file it generates these weird numbers as well. 

2.In the above screenshot you can see every entry has a header, there should be only one header and all the entries should come in line rather then using individual heading for every line printed. 

3.Apparently, you have not yet defined structure of Result_t to store your simulation results – without saving your simulation result in an array of Result_t, it is impossible to do Menu item 4, 5, and 7? 
	Please define result_t array to store simulation results. 


4.Apparently you opened two files but not closed in the same place ( or in same function) – This may cause problem in some cases, e.g., if some errors occurs during code development, making the program broken, then the opened file won’t be closed properly -As a result, the content of the file may become empty or Null due “not closed” (not sure if you have experience this case)
