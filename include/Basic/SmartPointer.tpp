namespace cusp {

template <typename TElem, typename TInt>
SmartPointer<TElem,TInt>::
SmartPointer(TElem *_cpuPtr, TInt _elemNum, bool deepCopy)
{
	sharedDataPtr = SharedDataPtrType(
		new SharedData<TElem,TInt>(_cpuPtr, _elemNum, deepCopy));
}

}
