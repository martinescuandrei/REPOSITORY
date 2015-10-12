#include "gtest/gtest.h" 
#include "Arguments.h"


// test count function
//TEST CASE 1
TEST(count,ReturnCount1)
{
	char *arg[1]={(char*)"main.exe"};
    Arguments argument(1,&arg[0]);
	ASSERT_EQ(0,argument.count());
}
//TEST CASE 2
TEST(count,ReturnCount2)
{
	char *arg[2]={(char*)"main.exe",(char*)"ARGUMENT"};
    Arguments argument(2,&arg[0]);
	ASSERT_EQ(1,argument.count());
}
// NE
//TEST CASE 1
TEST(count,ReturnCountNE1)
{
	char *arg[2]={(char*)"main.exe",(char*)"ARGUMENT"};
    Arguments argument(2,&arg[0]);
	ASSERT_NE(0,argument.count());
}


