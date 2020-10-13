#ifndef SHELF_H_H
#define SHELF_H_H
#include <iostream>
#include <string>
#include <vector>
#include "PrintBook.h"
using namespace std;

class Shelf{
	protected:
		vector<PrintBook> pbooks;
	public:
		Shelf(){
		}
		void addBook(PrintBook pb){
			pbooks.push_back(pb);
		}
		PrintBook getBook(int id){
			if(id<pbooks.size()-1){
			return pbooks[id];
			}else{
				cout<<"Error in Shelf id! \n";
			}
		}
		void print(){
		cout<<"Shelf contents: \n";
		for(int i=0;i<pbooks.size();i++){
			pbooks[i].Print();
		}
	}
};

#endif
