#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int depthGauge() {

    setlocale(LC_ALL, "rus");

    ifstream file;
    int more = 0;
    double kord;
    file.open("C:\\Users\\Asus\\Documents\\Bonch\\sem2\\algoritm\\Alg3\\matrix.txt");

    if (!file)
    {
        cout << "Файл не открыт\n\n";
        return -1;
    }
    else
    {
        cout << "Все ОК! Файл открыт!\n\n";
    }


    for (file >> kord; !file.eof(); file >> kord) {
        more++;
//        cout << kord << "  ";
    }


 //   cout << endl << more<<endl;
    more = sqrt(more);

    file.close();

  cout <<"В графе "<< more <<" вершин" << endl;

    return more;

}

int main(){

    setlocale(LC_ALL, "rus");

    int more=depthGauge();
    double** matrix;
    matrix = new double*[more];
    for (int i = 0; i < more; i++)
        matrix[i] = new double[more];


    ifstream file;
    
    double kord;
    file.open("C:\\Users\\Asus\\Documents\\Bonch\\sem2\\algoritm\\Alg3\\matrix.txt");

    if (!file)
    {
        cout << "Файл не открыт\n\n";
        return -1;
    }
    else
    {
        cout << "Все ОК! Файл открыт!\n\n";
    }

   
    for (int i = 0; i < more; i++){
        for (int j = 0; j < more;j++) {
            file >> matrix[i][j];
            cout << matrix[i][j]<<"  ";
        }
        cout << endl;
    } 

}