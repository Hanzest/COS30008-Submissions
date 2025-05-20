#include "SortableIntVector.h"

SortableIntVector::SortableIntVector( const int aArrayOfIntegers[], size_t aNumberOfElements ) : IntVector(aArrayOfIntegers, aNumberOfElements){
}

void SortableIntVector::sort(Comparable aOrderFunction){
    for(int i = 0; i < IntVector::size(); i++){
        for(int j = i + 1; j < IntVector::size(); j++){
            if(aOrderFunction(IntVector::get(i), IntVector::get(j))){
                IntVector::swap(i, j);
            }
        }
    }
}