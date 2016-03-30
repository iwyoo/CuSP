namespace cusp {

// constructor
template <typename TElem, typename TInt>
SmartPointer<TElem,TInt>::
SmartPointer(TElem *_cpuPtr, TInt _elemNum, bool deepCopy)
{
	sharedDataPtr = SharedDataPtrType(
		new SharedData<TElem,TInt>(_cpuPtr, _elemNum, deepCopy));
}

// copy constructor
template <typename TElem, typename TInt>
SmartPointer<TElem,TInt>::
SmartPointer(const SmartPointer<TElem, TInt>& _sp)
{
	sharedDataPtr = _sp.sharedDataPtr;
}

// destructor
template <typename TElem, typename TInt>
SmartPointer<TElem,TInt>::~SmartPointer()
{
}

}
