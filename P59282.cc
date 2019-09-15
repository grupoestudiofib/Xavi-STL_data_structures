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