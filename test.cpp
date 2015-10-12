#include "gtest/gtest.h" 
#include "Arguments.h"


// nr of arguments =1
//TEST CASE 1
TEST(appName,ReturnName1)
{
	char *arg[1]={(char*)"main.exe"};
    Arguments argument(1,&arg[0]);
	ASSERT_EQ("main.exe",argument.appName());
}

//TEST CASE 2
// more than one parameter
TEST(appName,ReturnName2)
{
	char *arg[2]={(char*)"main.exe" ,(char*) "argument" };
    Arguments argument(2,&arg[0]);
	ASSERT_EQ("main.exe",argument.appName());
}
//TEST CASE 3 
//for second parameter
TEST(appName,ReturnName3)
{
	char *arg[2]={(char*)"main.exe" ,(char*) "argument" };
    Arguments argument(2,&arg[1]);
	ASSERT_EQ("argument",argument.appName());
}