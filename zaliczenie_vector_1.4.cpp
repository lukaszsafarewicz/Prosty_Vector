#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <cmath>

using namespace std;

void wypisanie(vector<int> vec1);       //funkcja wypisujaca wektor
void plik(vector<int> vec);             // funkcja zapisuj¹ca wektor do pliku
int jak;
float srednia,suma,najblizsza=100000000,bezw;

int main()
{
    jak;
    vector <int> vec(30);
    cout<<"rozmiar vectora: "<< vec.size() << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = (rand () %100+1);       //wype³nienie wektora losowymi liczbami
        suma+=vec[i];                    //zliczanie liczb do wyliczenia sredniej
    }
    cout <<endl<<"Przed sortowaniem: "<<endl;
    wypisanie(vec);

    sort(vec.begin(), vec.end());        //sortowanie wektora funkcja z biblioteki

    cout <<endl<< "po sortowaniu: "<<endl;
    wypisanie(vec);
    plik(vec);                           //zapis vectora do pliku

    cout <<endl<<endl<<"suma wynosi: " <<suma;
    srednia=suma/vec.size();             //obliczenie œredniej
    cout <<endl<<endl<<"srednia wynosi: "<<srednia;
    cout <<endl<<endl;

    for (int i = 0; i < vec.size(); i++)
    {
     bezw = abs(vec[i]- srednia);
      if (bezw < najblizsza)            //pętla licząca wartość najbliżej średniej
      {
            najblizsza=bezw;
      }
    }
    najblizsza+=srednia;


    cout <<"liczba najblizsza sredniej "<<najblizsza<<endl;


return 0;
}
void plik(vector<int> vec)
{
    ofstream plik;
    plik.open("vector_Lukasz_Safarewicz1.txt");

    for(int i=0; i<vec.size(); i++)
    {
        plik<<vec[i]<<" ";
    }
    plik.close();
}
void wypisanie(vector<int> vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
        if ((i + 1) % 30 == 0) cout << endl;
    }
}
