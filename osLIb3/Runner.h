#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"RamClockMethod.h"
#include"RamLRU.h"
using namespace std;

class Runner {
private:
	 int total;
	 int seqSize;
	 int* seq;
	 int cntPerPage;

	 int cmd2page(int x) {
		 return x / cntPerPage;
	 }
public:
	Runner() {
		total = 320;
		seqSize = 1000;
		seq = new int[seqSize];
		cntPerPage = 10;
		srand((unsigned int)(time(NULL)));
		setSeq();
	}

	void setSeq() {
		for (int i = 0; i < seqSize; i++) {
			int m = rand() % total;
			seq[i] = m;

			if (i + 1 >= seqSize) break;
			i++;
			seq[i] = m + 1;
		
			if (i + 1 >= seqSize) break;
			i++;
			seq[i] = m + 2;


			int n = rand() % (m + 1);
			if (i + 1 >= seqSize) break;
			i++;
			seq[i] = n;
	
			if (i + 1 >= seqSize) break;
			i++;
			seq[i] = n + 1;
		

			int o = rand() % (total - n - 2) + n + 2;
			if (i + 1 >= seqSize) break;
			i++;
			seq[i] = o;
	
		}
		// test
		//for (int i = 0; i < seqSize; i++)
			//cout << seq[i] << " ";
		//cout << endl;
	}

	void run(Ram* ram) {
		int hit = 0;
		// ����ָ�����У�ָ�������ڳ�ʼ����ʱ���Ѿ�������
		for (int i = 0; i < seqSize; i++) {
			int n = cmd2page(seq[i]); 	// ָ���ҳ�ŵ�ӳ��
			cout << "Asking for page " << n << endl;
			ram->print(); // ��ӡ�ڴ���Ϣ
			// �ж��Ƿ����ڴ���
			if (ram->inRam(n)) {
				cout << "In memory!" << endl;
				// �����ڴ���Ϣ
				ram->update(n);
				hit++;
			}
			else { // �����ڴ���
				// �滻���߲���
				if (ram->isFull()) {
					cout << "Not in memory and a page will be replaced by this page!" << endl;
					ram->replace(n);
				}
				else {
					cout << "Not in memory and this page will insert into memory!" << endl;
					ram->insert(n);
				}
			}
			ram->print(); // ��ӡ�ڴ���Ϣ
		}
		// ����ӡ��ͳ����Ϣ
		ram->printMethod();
		cout << " and hit rate = " << (double)hit / seqSize << endl;
	}
};