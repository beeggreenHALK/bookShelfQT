#ifndef BSHELF_H
#define BSHELF_H
#include <iostream>
#include <string>
#include <vector>
#include "Shelf.h"
#include "PrintBook.h"

using namespace std;

class BookShelf{
	protected:
		vector<Shelf> shelfs;
	public:
        void addBook(PrintBook pb, int shelf_id){
            if(shelf_id<shelfs.size()-1){
                shelfs[shelf_id].addBook(pb);
			}else{
				cout<<"Error in Shelf id! \n";
			}
		}
		
        PrintBook getBook(int shelf_id, int book_id){
			if(shelf_id<shelfs.size()-1){
            shelfs[shelf_id].getBook(book_id);
		}else{
			cout<<"Error in Shelf id! \n";
		}
	}
	void addShelf(){
		Shelf shelf;
		shelfs.push_back(shelf);
	}
    int getShelfNumber(){
        return shelfs.size();
    }
	void Print(){
        cout<<"BookShelf info: "<<shelfs.size()<<":\n";
        for(int i=0;i<shelfs.size();i++) {
			cout<<"\t Shelf #"<<i++<<"\n";
            shelfs[i].print();
		}
	}
};

#endif
