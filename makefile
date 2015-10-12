RM = rm
CPPTOOL = g++
CPPFLAGS = -Wall
GTEST_DIR=C:\gtest-1.7.0
GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a
GTEST_INC=-isystem $(GTEST_DIR)\include
CPP = $(CPPTOOL) $(CPPFLAGS) -c
LINK = $(CPPTOOL) -o

all: main.exe test.exe test_count.exe test_constr.exe

main.exe: main.o Arguments.o
	$(LINK) main.exe main.o Arguments.o

main.o: main.cpp Arguments.h
	$(CPP) main.cpp

Arguments.o: Arguments.cpp Arguments.h
	$(CPP) Arguments.cpp

test: test.o Arguments.o Arguments.h $(GTEST_LIB)
	$(LINK) test.exe test.o Arguments.o Arguments.h $(GTEST_LIB)
	
test_count: test_count.o Arguments.o Arguments.h $(GTEST_LIB)
	$(LINK) test_count.exe test_count.o Arguments.o Arguments.h $(GTEST_LIB)

test_constr: test_constr.o Arguments.o Arguments.h $(GTEST_LIB)
	$(LINK) test_constr.exe test_constr.o Arguments.o Arguments.h $(GTEST_LIB)

test_try: test_try.o Arguments Arguments.h $(GTEST_LIB) 
	$(LINK) test_try.exe test_try.o Arguments.o Arguments.h $(GTEST_LIB)

test.o: test.cpp Arguments.h
	$(CPP) test.cpp $(GTEST_INC)
	
test_constr.o: test_constr.cpp Arguments.h
	$(CPP) test_constr.cpp $(GTEST_INC)

test_count.o: test_count.cpp Arguments.h
	$(CPP) test_count.cpp $(GTEST_INC) 

test_try.o: test_try.cpp Arguments.h
	$(CPP) test_try.cpp $(GTEST_INC)	
	
test.exe: test
	test.exe

test_count.exe: test_count
	test_count.exe

test_constr.exe: test_constr
	test_constr.exe
	
test_try.exe: test_try
	test_try.exe


clean:
	$(RM) Arguments.o
	$(RM) main.o
	$(RM) main.exe
	$(RM) test.exe
	$(RM) test.o
	$(RM) test_count.exe
	$(RM) test_count.o
	$(RM) test_constr.exe
	$(RM) test_constr.o
