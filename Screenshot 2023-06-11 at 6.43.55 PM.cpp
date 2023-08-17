#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int value;
    char answer;
    int connectionType, n = 0;
    int resistor[1000];
    double totalResistance = 0;


    do {    //adding a do while to get the output all on one terminal

        cout << "Select Connection: 1) Series 2) Parallel: ";
        cin >> connectionType;

        cout << "Enter the number of resistors connected: ";
        cin >> n;

        if (n > 1000)
        {
            cout << "The number of resistors cannot exceed 1000." << endl;
            return 1;
        }

        for (int i = 0; i < n; i++)
        {

            cout << "Enter the value for each resistor " << i + 1 << ": ";
            cin >> value;


            resistor[i] = value;
        }

        if (connectionType == 1)
        {
            cout << "Total series resistance is ";
            for (int i = 0; i < n; i++)
            {
                totalResistance += resistor[i];
                cout << resistor[i] << " Ohm";
                if (i < n - 1)
                {
                    cout << ", ";
                }
            }
            cout << " for the " << n << " resistors." << endl;
        }
        else if (connectionType == 2)
        {
            cout << "Total parallel resistance is ";
            for (int i = 0; i < n; i++)
            {
                totalResistance += 1 / (double)resistor[i];
                cout << resistor[i] << " Ohm";
                if (i < n - 1)
                {
                    cout << ", ";
                }
            }
            totalResistance = 1 / totalResistance;
            cout << " for the " << n << " resistors." << endl;
        }
        else
        {
            cout << "Invalid connection type. (Must be 1 or 2)" << endl;
            return 1;
        }

        if (totalResistance < 1000)
        {
            cout << "Equivalent Resistor Value: " << (int)totalResistance << " Ohm" << endl;
        }
        else
        {
            cout << fixed << setprecision(3);
            cout << "Equivalent Resistor Value: " << (totalResistance / 1000) << " KOhm" << endl;
        }


        cout << endl;


        cout << "repeat? y or n ";
        cin >> answer;
    } while (answer == 'y');

    return 0;
}

