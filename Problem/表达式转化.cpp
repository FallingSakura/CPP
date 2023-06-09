#include<bits/stdc++.h>

using namespace std;

// �ж��Ƿ�Ϊ����
bool isPra(char c) {
    return (c == '(' || c == ')') ? true : false;
}

// ��÷��ŵ�������
int getPri(char c)
{
    switch (c) {
    case '+':
    case '-':
        return 0;   // ����ǼӼ�������0
        break;
    case '*':
    case '/':
        return 1;   // ����ǳ˳�������1
        break;
    case '(':
    case ')':
        return -1;  // ���ｫ������Ϊ������ȼ���������Ų��ᱻ��������������������
        break;
    default:
        cout << "�������������\n" << endl;
    }
}

//�жϷ��ŵ�������
void check(char c, stack<char>& operator_s, string& suffix) {
    if (operator_s.empty()) {
        operator_s.push(c);
        return;
    }
    
    if (isPra(c)) {
        if (c == '(') {
            operator_s.push(c);
        }
        else {
            // ��������Ԫ��ֱ������������
            while (operator_s.top() != '(') {
                suffix += operator_s.top();
                operator_s.pop();
            }

            // ���������ţ������Ҳ������׺���ʽ
            operator_s.pop();
        }
    }
    else {
        // ����������ţ��Ƚϵ�ǰԪ�أ���ջ��Ԫ�ص����ȼ�
        if (getPri(c) > getPri(operator_s.top())) {
            operator_s.push(c);
        }
        else {
            suffix += operator_s.top();
            operator_s.pop();

            // �ݹ���ã��Ƚϵ�ǰ����c����һ��ջ�����ŵ�������
            check(c, operator_s, suffix);
        }
    }
}

// ��׺���ʽת��׺���ʽ
string infixToSuffix(string& infix) {
    stack<char> operator_s; // �����ջ
    string suffix;          // ��׺���ʽ

    //int num = 0;
    for (int i = 0; i < infix.size(); ++i) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            suffix += infix[i];
        }
        else {
            check(infix[i], operator_s, suffix);
        }
    }

    // ����׺���ʽ�ı�����������ջ��Ԫ�ؼ����׺���ʽ
    while (!operator_s.empty()) {
        suffix += operator_s.top();
        operator_s.pop();
    }

    return suffix;
}

int main ()
{
	 
	return 0;
}

