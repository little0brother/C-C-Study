1. struct teacher 
  {
		int id;
		struct teacher t1;

  }; 

 ���ֽṹ�������ܹ�����ͨ����Ϊʲô��



2. ������������������



3. �ѿ����ϵ�������Ļ�������������һ�顣
	//����ͷ�ڵ㣬�����ͷ����ַ�ɺ���ֵ���ء�
	SLIST *SListCreat();
	
	//�����ڵ�
	//˳�������������������������е�����
	int SListPrint(SLIST *pHead);
	
	//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻
	//��ֵΪx�Ľ�㲻���ڣ�����ڱ�β
	int SListNodeInsert(SLIST *pHead, int x, int y);

	//ɾ����һ��ֵΪx�Ľ��
	int SListNodeDel(SLIST *pHead, int x);
	
	//�ͷ����нڵ�
	int SListDestroy(SLIST *pHead);


4. ������ϰ( ���Ӳο�<�����������.exe> )��
	//ɾ��ֵΪx�����н��
	int SListNodeDelPro(SLIST *pHead, int x);
	
	//����ڵ�����
	int SListNodeSort(SLIST *pHead);
	//ע�⣬���򣬳�����������Ҫ������nextָ�뻹��Ҫ����
		if (pPre->id > pCur->id) //����
		{
			//����������
			tmp = *pCur;
			*pCur = *pPre;
			*pPre = tmp;

			//����ָ������Ҫ��
			tmp.next = pCur->next;
			pCur->next = pPre->next;
			pPre->next = tmp.next;
		}
	
	//����ԭ�������������,��������½ڵ�
	//���ܲ���ڵ������������������½ڵ�x
	int SListNodeInsertPro(SLIST *pHead, int x);
	
	//��ת����Ľڵ㣨���������Ƿ�ת��
	int SListNodeReverse(SLIST *pHead);
	

5. ͨ���ݹ�ʵ�֣�1+2+����+100���ۼ�

