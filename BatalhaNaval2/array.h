#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
template<typename T>
class ArrayList
{
public:
	friend std::ostream& operator<<(std::ostream& out, ArrayList<T>& vetor) {
		if (vetor.size() == 0) {
			out << "[]";
			return out;
		}
		out << "[";
		for (int i = 0; i < vetor.size(); i++) {
			out << vetor.Lista[i];
			if (i != vetor.size() - 1) {
				out << ", ";
			}
		}
		out << "]";

		return out;
	}
	ArrayList() {
		Lista = new T[tamanhoInicial];
		this->condicao = false;
	};
	ArrayList(int tamanhoInicial) {
		Lista = new T[tamanhoInicial];
		this->condicao = false;
	};

	//sim ou nao
	ArrayList(std::string string)
	{
		if (string == "sim")
		{
			this->condicao = true;
		}
		else {
			this->condicao = false;
		}
	}
	~ArrayList();
	//pronto
	bool add(T elemento);
	//pronto
	void addPassandoIndice(T elemento, int index);
	//pronto
	void clear();
	//pronto
	T get(int index);
	//pronto
	bool contains(T elemento);
	//pronto
	int indexOf(T elemento);
	//pronto
	bool isEmpty();
	//pronto
	int lastIndexOf(T elemento);
	//pronto
	T remove(int index);
	//pronto
	int size();
	//pronto
	void resize(int tamanho);

private:
	bool condicao;
	T* Lista;
	int tamanhoInicial = 3;
	int tamanho = 0;
	bool checarSeExisteIndex(int index);
};


template<typename T>
inline ArrayList<T> :: ~ArrayList() {
	delete[] this->Lista;
}

template<typename T>
inline bool ArrayList<T> ::add(T elemento) {

	resize(this->tamanho);
	this->Lista[this->tamanho] = elemento;
	this->tamanho++;
	return true;

}
//remover passando index
template<typename T>
inline T ArrayList<T>::remove(int index) {
	T elemento = this->Lista[index];
	if (this->checarSeExisteIndex(index))
	{
		for (int i = index; i < this->tamanho - 1; i++)
		{
			this->Lista[i] = this->Lista[i + 1];
		}
	}
	this->tamanho--;
	this->Lista[this->tamanho] = 0;
	return elemento;
}

template<typename T>
inline void ArrayList<T> ::addPassandoIndice(T elemento, int index) {
	if (this->condicao == false)
	{
		resize(this->tamanho);
		if (checarSeExisteIndex(index)) {
			for (int i = tamanho - 1; i >= index; i--)
			{
				this->Lista[i + 1] = this->Lista[i];
			}
			this->Lista[index] = elemento;
			this->tamanho++;
		}
	}
	else {
		if (contains(elemento) == false)
		{
			resize(this->tamanho);
			if (checarSeExisteIndex(index)) {
				for (int i = tamanho - 1; i >= index; i--)
				{
					this->Lista[i + 1] = this->Lista[i];
				}
				this->Lista[index] = elemento;
				this->tamanho++;
			}
		}
		else
		{
			std::cout << "Elemento ja existe. " << std::endl;
		}

	}







}

template<typename T>
inline void ArrayList<T> ::clear() {
	delete[] this->Lista;
	this->Lista = new T[this->tamanhoInicial];
	this->tamanho = 0;

}

template<typename T>
inline void ArrayList<T> ::resize(int tamanho) {

	//int tamanhoVetor = sizeof(this->Lista) / sizeof(this->Lista[0]);
	//tamanhoVetor * 2
	if (tamanho == this->tamanho) {

		T* ListaNova = new T[size() * 2];

		for (int i = 0; i < size(); i++) {
			ListaNova[i] = this->Lista[i];
		}
		this->Lista = ListaNova;
	}
}

template<typename T>
inline bool ArrayList<T>::checarSeExisteIndex(int index)
{

	return index >= 0 && index < this->tamanho;



}

template<typename T>
inline T ArrayList<T>::get(int index) {
	if (this->checarSeExisteIndex(index)) {
		return this->Lista[index];
	}

	return T();


}

template<typename T>
inline bool ArrayList<T>::contains(T elemento) {
	for (int i = 0; i < this->tamanho; i++)
	{
		if (elemento == (this->Lista[i])) {
			return true;
		}
	}
	return false;
}

template<typename T>
inline int ArrayList<T>::indexOf(T elemento)
{
	for (int i = 0; i < this->tamanho; i++)
	{
		if (elemento == this->Lista[i]) {
			return i;
		}
	}
	return 0;
}

template<typename T>
inline int ArrayList<T>::size() {
	return this->tamanho;
}

template<typename T>
inline bool ArrayList<T>::isEmpty() {
	return this->tamanho == 0;
}

template<typename T>
inline int ArrayList<T>::lastIndexOf(T elemento) {
	int indice = 0;
	for (int i = 0; i < this->tamanho; i++)
	{
		if (elemento == Lista[i])
		{
			indice = i;
		}
	}
	return indice;
}


