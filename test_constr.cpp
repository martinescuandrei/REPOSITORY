#include "gtest/gtest.h" 
#include "Arguments.h"


//TEST CASE 1
TEST(constr,ReturnVectorConstructor1)
{
	char *arg[3]={(char*)"main.exe",(char*)"1",(char*)"2"};
	Arguments argument(2, &arg[2]);
	argument.appName() = arg[0];
	
	for (int i = 1; i < argument.count(); i++)
	{	
	ASSERT_EQ(arg[i+1],argument[i]);	
	}	           
}
//TEST CASE 2 FOR COPY CONSTRUCTOR
TEST(constr,ReturnVectorConstructorCopy1)
{
	char *arg[3]={(char*)"main.exe",(char*)"1",(char*)"2"};
	Arguments argument(2, &arg[2]);
	Arguments argumentCopy(argument);
	argument.appName() = arg[0];
	
	for (int i = 1; i < argument.count(); i++)
	{	
	ASSERT_EQ(argument[i+1],argumentCopy[i]);	
	}	           
}
//TEST CASE 3 FOR ASSIGNMENT CONSTRUCTOR
TEST(constr,ReturnVectorConstructorAssignment1)
{
	char *arg[3]={(char*)"main.exe",(char*)"1",(char*)"2"};
	Arguments argument(2, &arg[2]);
	Arguments argumentCopy(argument);
	Arguments argumentAssignment(argument);
	argumentAssignment=argumentCopy;
	argument.appName() = arg[0];
	
	for (int i = 1; i < argument.count(); i++)
	{	
	ASSERT_EQ(argumentCopy[i+1],argumentAssignment[i]);	
	}	           
}
// Test's for try catch
//TEST CASE 1
//TEST EXCEPTION InvalidArguments
TEST(constr,InvalidArguments)
{
	char *arg[3]={(char*)"main.exe",(char*)"1",(char*)"2"};
	int NrOfArg = -1;
	bool flag = false;
	
try
    {
		Arguments argument(NrOfArg, &arg[2]);
    }
    catch (int e)
    {
       flag = true;
    }	
	
	EXPECT_EQ(true,flag);	
}

//TEST EXCEPTION InvalidArguments
TEST(constr,InvalidArgumentsArgv1)
{
	char *arg[0]={};
	int NrOfArg = 1;
	bool flag = false;
	
try
    {
		Arguments argument(NrOfArg,arg);
		/* enters in try catch from Constructor but try catch is only 
		a catch for argc not for argv , doesn't return the catch*/
    }
    catch (int e)
    {
       flag = true;
    }	
	// it doesn't enter in local catch so expexted is false , initial flag
	EXPECT_EQ(true,flag);	
}

//TEST EXCEPTION InvalidArguments
TEST(constr,InvalidArgumentsArgv2)
{
	char **arg1={};
	int NrOfArg = 1;
	bool flag = false;
	
try
    {
		Arguments argument(NrOfArg,arg1);	
    }
    catch (int e)
    {
       flag = true;
    }	
	
	EXPECT_EQ(true,flag);	
}



