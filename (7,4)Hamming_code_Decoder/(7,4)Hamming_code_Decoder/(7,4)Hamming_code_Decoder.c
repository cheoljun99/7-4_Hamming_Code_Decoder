// (7,4) Hamming code Decoder
#include<stdio.h>
#include<string.h>

int main() {
	printf("Hamming ���ڴ� (�Է� 7-bit, ��� 4-bit, z ���� ��°��� �ƴ�)\n");
	while (1)
	{
		char input[8] = { 0 };
		int parity_check_matrix_H[3][7] = {
			//�ŵ�� ���� ���
			{1,1,1,0,1,0,0},
			{0,1,1,1,0,1,0},
			{1,0,1,1,0,0,1}
		};
		int received_codeword_r[7] = { 0, };
		int syndrome_z[3] = { 0, };
		int syndrome_table[8] = { 0,7,6,4,5,1,2,3 };
		char result[5] = { 0 };
		char z_result_for_test[4] = { 0 };


		printf("�Է�: ");
		scanf("%s", input);
		for (int i = 0; input[i]; i++) {
			received_codeword_r[i] = input[i] - '0';
		}
		//�Էº�Ʈ�� �ŵ�� ��������� ��Ŀ����� ���� 3��Ʈ�� ���ϴµ� �̶� ����ϴ� ������ modulo-2 ���� �������� ����Ѵ�.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++)
				if (parity_check_matrix_H[i][j] == 1)
				{
					syndrome_z[i] ^= received_codeword_r[j];
				}
		}
		sprintf(z_result_for_test, "%d%d%d", syndrome_z[0], syndrome_z[1], syndrome_z[2]);
		
		int table_checker = syndrome_z[0] * 4 + syndrome_z[1] * 2 + syndrome_z[2];//�ŵ�� ǥ�� �ε����� ���ϱ�
		

		/*
		//Z���� ����Ͽ� corrected bit�� ã������ �κ�(test �ڵ�) 
		printf("���: z=%s ", z_result_for_test);
		if (temp == 0)
		{
			printf("(no error corrected)\n");
		}
		else
		{
			printf("(r%d corrected)\n", syndrome_table[temp]);
		}
		*/

		if (table_checker != 0) {
			//�ŵ�� ���̺��� �����Ͽ� corrected bit�� ����
			if (received_codeword_r[syndrome_table[table_checker] - 1] == 1)
				received_codeword_r[syndrome_table[table_checker] - 1] = 0;
			else
				received_codeword_r[syndrome_table[table_checker] - 1] = 1;
		}
		sprintf(result, "%d%d%d%d", received_codeword_r[0], received_codeword_r[1], received_codeword_r[2], received_codeword_r[3]);
		printf("���: %s\n", result);

	}
	
	return 0;
}