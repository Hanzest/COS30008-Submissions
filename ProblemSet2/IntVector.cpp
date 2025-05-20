#include "IntVector.h"
#include<stdexcept>

IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements){
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];
    for(int i = 0; i < fNumberOfElements; i++){
        fElements[i] = aArrayOfIntegers[i];
    }
}

IntVector::~IntVector(){
    delete[] fElements;
}

size_t IntVector::size() const{
    return fNumberOfElements;
}

const int IntVector::get(size_t aIndex) const{
    if(aIndex < 0 || fNumberOfElements <= aIndex) throw std::out_of_range("Illegal vector index");
    else return fElements[aIndex];
}

void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex ){
    size_t tempSource = get(aSourceIndex);
    size_t tempTarget = get(aTargetIndex);
    // test for out of range cases
    fElements[aSourceIndex] = tempTarget;
    fElements[aTargetIndex] = tempSource;
}

const int IntVector::operator[](size_t aIndex) const{
    if(aIndex < 0 || fNumberOfElements <= aIndex) throw std::out_of_range("Illegal vector index");
    else return fElements[aIndex];
}