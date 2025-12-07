#include <iostream>
using namespace std;

int posCaries(int *arr, int ini, int fin, int t) {

    if (ini == fin) return ini; //retorna la posición del número menor más cercano a T.
    int medio=(ini+fin)/2;

    if (arr[medio]>t) {
        return posCaries(arr, medio+1, fin, t);
    }
    return posCaries(arr, ini, medio, t);


}
int main(){

    int arr[]={98, 96, 93, 90, 72, 60, 55, 50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int t=96;
    int pos=posCaries(arr, 0, n-1, t);
    // cout << t<<endl;
    if (pos==n-1) {
        if (arr[pos]>=t) {
            cout <<"No se detecta caries clínica"<<endl;
            return 0 ;
        }
    }
    if (arr[pos]==t) {
        pos++; // esto ya que las caries aparecen una vez bajen el limite. entonces (caries < T), (saludable >=T)
    }
    cout << "Primera zona con caries clínica detectada en la posición ";
    cout << pos <<endl;
    cout << "Densidad registrada: "<< arr[pos]<<endl;



    return 0;
}