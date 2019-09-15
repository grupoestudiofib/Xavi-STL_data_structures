//AYUDA: Creo que el error está al eliminar en el delete o directamente en la estructura de datos que uso; el mayor problema/duda está en cómo añadir elementos repetidos sin que haya problemas del solapamiento y tal
//Me da error al eliminar un numero que estaba repetido así que ahí mi duda pls help

#include <iostream>
#include <set>
using namespace std;

int main(){
	set<int> s;
	string act;
	double tot = 0;
	int tam = 0;
	auto it = s.begin();
	//minimo en s.begin(); maximo en s.end() -1
	while(cin >> act){
		auto fin = s.end();
		//puntero para el número máximo
		if(act == "delete"){
			if(s.size() == 0) cout << "no elements" << endl;
			//si el set está vacío no hace nada
			else{
				//delete elimina el minimo (s.begin()); disminuimos el tamaño y restamos el menor al total
				--tam;
				tot-= *(s.begin());
				it = s.erase(s.begin());
				//eliminamos el menor
				--fin;
				//colocamos el puntero en s.end()-1 (maximo) e imprimimos
				cout << "minimum: " << *(s.begin()) << ", maximum: " << *fin << ", average: " << tot/tam << endl;
			}
		}
		else if(act == "number"){
			//aumentamos el tamaño en uno, añadimos n al total y lo insertamos
			++tam;
			int n;
			cin >> n;
			tot+=n;
			it = s.insert(n).first;
			//colocamos el puntero en s.end()-1 (maximo) e imprimimos
			--fin;
			cout << "minimum: " << *(s.begin()) << ", maximum: " << *fin << ", average: " << tot/tam << endl;
		}
	}
}
/*
Adri:
El set te elimina los valores repetidos, si te entran dos valores repes ya estas contaminando las estadisticas
	idea 1: mirar antes de meter los elementos si estan repes con bool repe = s.find(elem) == s.end() y tenerlo en cuenta con tam y tot
	idea 2: Yo probaria a usar priority_queue que creo que es la unica de entre set map y pq que permite repes
	tal vez haciendo dos colas una pq normal y otra invertida para pillar los maximos y minimos no se
	idea 3(la mas interesante para mi): hacerlo con un map<int,int> (k,v) en el que k sea el numero y v las veces que esta repe, y que al hacer delete se mire v
	si es 0 a tomar fanta y si no se reduce (al añadir tambien tenerlo en cuanta si esta ya sumarle 1 a la v)
*/
