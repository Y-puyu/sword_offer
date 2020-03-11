// Junior programmer writing
CMyString& CMyString::operator=(const CmyString &str) {
	if (this == &str)
		return *this;
	
	delete []m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
};

// A solution that considers exception safety, essential for advanced programmers
CMyString& CMyString::operator=(const CMyString &str) {
    if(this !=&str) {
        CMyString strTemp(str); // 先创建一个临时对象strTemp
        char* pTemp=strTemp.m_pData;
        strTemp.m_pData=m_pData; // 再把strTemp.m_pData和自身的m_pData进行交换。
        m_pData=pTemp；
        // 由于stremp是个局部对象，运行到if作用域外，就会自动调用strtemp的析构函数从而完成了内存的释放。
        // 由于strTemp.m_pData指向的内存就是m_pData的内存，就相当于自动调用析构函数释放实例的内存。
        // 同时也完成了相应的拷贝工作。
    }
    return *this;
}
