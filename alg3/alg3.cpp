#include <iostream>
#include <fstream>
#include <ostream>
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
    ofstream inter;
    
    double kord;
    file.open("C:\\Users\\Asus\\Documents\\Bonch\\sem2\\algoritm\\Alg3\\matrix.txt");
    inter.open("C:\\Users\\Asus\\Documents\\Bonch\\sem2\\algoritm\\Alg3\\inter.txt");

    if (!file)
        return -1;
    
   
    for (int i = 0; i < more; i++){
        for (int j = 0; j < more;j++) {
            file >> matrix[i][j];
            cout << matrix[i][j]<<"  ";
        }
        cout << endl;
    } 
    file.close();




    int rebr=0;

    for (int i = 0; i < more;i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0)
                rebr++;
        }
    }

    cout<<endl <<"Количество вершин = "<<more <<"  Количество ребер = "<<rebr<<endl;


    rebr -= more - 1;

    cout << "Необходимо удалить "<< rebr <<" ребра"<< endl;

    double min = 0;

    for (int i = 0; i < more; i++) {
        min = 6000000;
        for (int j = 0; j < more; j++) {
            if (matrix[i][j] < min && matrix[i][j] != 0) {
                min = matrix[i][j];
            }
            else { 
                matrix[i][j] = 0;
                matrix[j][i] = 0;                       
            }
        }
    }

    cout << endl; cout << endl; cout << endl; cout << endl;


    for (int i = 0; i < more; i++) {
        for (int j = 0; j < more; j++) {
            cout << matrix[i][j] << "  ";
            inter << matrix[i][j]<<" ";

        }
        cout << endl;
        inter << endl;
    }


    inter << endl<< endl<< endl;


    file.open("C:\\Users\\Asus\\Documents\\Bonch\\sem2\\algoritm\\Alg3\\matrix.txt");

    if (!file)
        return -1;
    


    cout << endl;

    for (int i = 0; i < more; i++) {
        for (int j = 0; j < more; j++) {
            file >> matrix[i][j];
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    file.close();





}