#include "BlackjackRules.h"
#include <iostream>

void BlackjackRules::displayRules() {
    std::cout << R"(



   *********       � � � � � � �  � � � �  �  B L A C K J A C K G A M E :       *********

   1. ���� ���� - ������� ����� ���, ����� ����� �� ��������� ���� ��� ����� ����� � 21, 
      �� �� ��������� ����� ��������.
   2. �������� ����:
      - ����� �� 2 �� 10 ����� �������, ������ �� ��������� ��������.
      - ����� (J), ���� (Q), ������ (K) ����� ������� 10.
      - ��� (A) ����� ����� �������� 1 ��� 11, � ����������� �� ��������.
   3. ����� � ����� �������� �� ��� �����. 
   4. ����� ����� ����� �������������� ����� ('����� ���') ��� ���������� ('����������').
   5. ����� ����� �������������� �����, ���� ����� ��� ���� �� ��������� ��� �������� 17.
   6. ��������� �����, ��� ����� ����� � 21 � �� ��������� 21. � ������ ��������� - �����.
   7. �������� - ����� 21 ���� � ����� ������� (��� � ����� ��������� 10).







)";
}