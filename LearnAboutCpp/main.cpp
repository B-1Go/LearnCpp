// �ּ�
//  ���� ����, �ڵ�� �νĵ��� �ʴ´�.

int main()
{
	// �ڷ��� (ũ�� ����, 1byte = 8bit) Data Type
	// ������ : char(1), short(2), int(4), long(4), long long(8)
	// �Ǽ��� : float(4), double(8)
	int i = 0;
	unsigned char c = 0; // ���� ������

	c = 0; // 256���� -> 0~255
	c = 256; // 1 0000 0000 => 8���� ������ 0	9��° ��Ʈ�� 1����Ʈ�� ���� �� ���� ������ ����

	// �⺻������ signed�� �Ǿ��ְ� �������ִ�.
	signed c1 = 0; // 256���� -> -128~127
	// �ǳ�(���ʳ�) Most Siginficant Bit(MSD) 0: ���, 1: ����
	c1 = -1;

	// ��ǻ�ʹ� ��� ������ �������� ó���ϱ� ������
	// ������ ���ٹ���� �ٲ㼭 �����ؾ� �Ѵ�.
	// https://www.youtube.com/watch?v=YN0jMyJR31M&list=PL4SIC1d_ab-aOxWPucn31NHkQvNPHK1D1&index=4 20:30

	return 0;
}