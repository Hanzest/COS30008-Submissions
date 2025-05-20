#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector( const int aArrayOfIntegers[], size_t aNumberOfElements ) : SortableIntVector(aArrayOfIntegers, aNumberOfElements){
}

void ShakerSortableIntVector::sort( Comparable aOrderFunction){
    int beginIndex = 0;
    int endIndex = IntVector::size();
    for(int i = 0; i < endIndex; i++){
        for(int j = i; j < endIndex - 1; j++){
            if(aOrderFunction(IntVector::get(j), IntVector::get(j + 1))){
                IntVector::swap(j, j + 1);
            }
        }
        endIndex--;
        for(int j = endIndex; j >= beginIndex + 1; j--){
            if(aOrderFunction(IntVector::get(j - 1), IntVector::get(j))){
                IntVector::swap(j, j - 1);
            }
        }
    }
}