/// App using the Arugments class
#include <iostream>

#include "Arguments.h"


int main( int argc, char* argv[] )
{
    using namespace std;

    try
    {
        Arguments args(argc, argv);
		Arguments args1(args);
		Arguments args2(args);
		args2=args1;
		cout << "Name of the application: " <<
            args.appName() << endl;
		cout << "Nr of parameters:\n";
		cout << args.count() <<endl;
        for ( int i = 0; i < args.count(); ++i )
        {
            cout << args[i] << endl;
        }
		//copy constructor 
		cout << "copy constructor\n";
		cout << "nr of parameters:\n";
		cout << args1.count() <<endl;
		for ( int i = 0; i < args1.count(); ++i )
		{
			cout << args1[i] <<endl;
		}
		// copy construct with =
		cout << "copy constructor with =\n";
		cout << "nr of parameters:\n";
		cout << args2.count() <<endl;
		for ( int i = 0; i < args2.count(); ++i )
		{
			cout << args2[i] <<endl;
		}
		
    }
    /// This will catch throws from the try block with an integer param
    catch (int e)
    {
        cerr << "Construction error occured..." << endl;
    }
    /// This will catch throws from the try block with a size_t param
    catch (size_t e)
    {
        cerr << "Out of range error occured ..." << endl;
    }

    cout << "Ending application... " << endl;
    return 0;
}
