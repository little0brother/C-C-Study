1. struct teacher 
  {
		int id;
		struct teacher t1;

  }; 

 这种结构体类型能够编译通过，为什么？
 	答：不能通过编译，因为结构体的类型大小无法确定



2. 简述链表和数组的区别？
	答：数组在创建时确定内存空间大小，是一种按照顺序存储的一种类型，查找速度快，但插入，删除元素比较困难
		链表不按照固定的空间存储内容，而是用的时候再确定在哪一块空间进行存储，不是按照内存空间顺序存储，查找值较慢，但插入，修改内存方便


3. 把课堂上单向链表的基本操作重新敲一遍。
	//创建头节点，链表的头结点地址由函数值返回。
	SLIST *SListCreat();
	
	//遍历节点
	//顺序输出单向链表各项结点数据域中的内容
	int SListPrint(SLIST *pHead);
	
	//在值为x的结点前，插入值为y的结点；
	//若值为x的结点不存在，则插在表尾
	int SListNodeInsert(SLIST *pHead, int x, int y);

	//删除第一个值为x的结点
	int SListNodeDel(SLIST *pHead, int x);
	
	//释放所有节点
	int SListDestroy(SLIST *pHead);


4. 链表练习( 例子参考<链表基本操作.exe> )。
	//删除值为x的所有结点
	int SListNodeDelPro(SLIST *pHead, int x);
	
	//链表节点排序
	int SListNodeSort(SLIST *pHead);
	//注意，排序，除了数据域需要交换，next指针还需要交换
		if (pPre->id > pCur->id) //升序
		{
			//交换数据域
			tmp = *pCur;
			*pCur = *pPre;
			*pPre = tmp;

			//交换指针域（重要）
			tmp.next = pCur->next;
			pCur->next = pPre->next;
			pPre->next = tmp.next;
		}
	
	//假如原来链表是升序的,升序插入新节点
	//不能插入节点后再排序，是升序插入新节点x
	int SListNodeInsertPro(SLIST *pHead, int x);
	
	//翻转链表的节点（不是排序，是翻转）
	int SListNodeReverse(SLIST *pHead);
	

5. 通过递归实现：1+2+……+100的累加

