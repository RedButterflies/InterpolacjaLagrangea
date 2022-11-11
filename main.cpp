#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Wprowadz liczbe wezlow" << endl;
    int liczbaWezlow;
    cin>>liczbaWezlow;
    float wezly[liczbaWezlow];

    for(int i=0;i<liczbaWezlow;i++)
    {
        cout<< "Wprowadz wartosc dla wezla "<<i<<endl;
        cin>>wezly[i];
        float mniejszy= wezly[i];
        //Sprawdzenie warunkow interpolacji
        //Czy wezly interpolacji sa rozne miedzy soba
        if(wezly[i]==wezly[i-1])
        {
            cout<<"Wezly interpolacji nie sa rozne miedzy soba. Wprowadz prawidlowe wartosci"<<endl;
        }
        //Czy wezly interpolacji sa ulozone w porzadku rosnacym
        if(i!=0&& mniejszy < wezly[i-1])
        {
            cout<<"Wezly nie sa ulozone w porzadku rosnacym. Wprowadz poprawne dane"<<endl;
        }
    }
    float wartoscFunkcji[liczbaWezlow];
    for(int i=0;i<liczbaWezlow;i++)
    {
        cout<< "Wprowadz wartosc funkcji w wezle "<<i<<endl;
        cin>>wartoscFunkcji[i];
    }
    cout<<"Wprowadz wartosc punktu p: "<<endl;
    float punkt;
    cin>>punkt;
    double wielomianyFundamentalne[liczbaWezlow];
    for(int i=0;i<liczbaWezlow;i++){wielomianyFundamentalne[i]=1.0;}
    wielomianyFundamentalne[0]=1.0;
    float wielomianFundamentalny[liczbaWezlow];
    for(int i=0;i<liczbaWezlow;i++){wielomianFundamentalny[i]=1.0;}


    //Sprawdzenie czy punkt nalezy do przedzialu wyznaczonego przez wezly
    if(punkt >= wezly[0] && punkt <=wezly[liczbaWezlow-1])
    {
        cout<<"Punkt nalezy do przedzialu, przechodze do obliczania przyblizonej wartosci"<<endl;
        for(int i=0;i<liczbaWezlow;i++)
        {
            //cout<<"wartosc funkcji "<<wartoscFunkcji[i]<<endl;
            for(int j=0;j<liczbaWezlow;j++)
            {
                if(j==i)continue;


                float dzielna =punkt-wezly[j];
                float dzielnik = wezly[i]-wezly[j];
                //cout<<"dzielna "<<dzielna<<endl;
                //cout<<"dzielnik "<<dzielnik<<endl;
                wielomianFundamentalny[j]=dzielna/dzielnik;
                //cout<<"M"<<wielomianFundamentalny[j]<<endl;
                wielomianyFundamentalne[i]*= wielomianFundamentalny[j];

            }
            //cout<<"C"<<wielomianyFundamentalne[i]<<endl;

        }
        float wielomianInterpolacyjny;
        float suma=0.0;
        for(int i=0;i<liczbaWezlow;i++)
        {
            suma+=float(wielomianyFundamentalne[i]*wartoscFunkcji[i]);
        }
        wielomianInterpolacyjny=suma;
        cout<< "Przyblizona wartosc wielomianu interpolacyjnego dla podanych wartosci to: "<<endl;
        cout<<wielomianInterpolacyjny<<endl;

    }
    else
    {
        cout<<"Punkt nie nalezy do przedzialu, prosze podac odpowiedni punkt i sprobowac ponownie"<<endl;
    }



    return 0;
}
