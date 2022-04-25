# 리스트 (List)

<br>

## 리스트 구현
- [Array](https://github.com/33bini/42-study_datastructure2022/tree/main/2_List/1_ArrayList), [Linked](https://github.com/33bini/42-study_datastructure2022/tree/main/2_List/1_SinglyLinkedList) List 구현하기
- [circular](https://github.com/33bini/42-study_datastructure2022/tree/main/2_List/2_CircularLinkedList), [double linked list](https://github.com/33bini/42-study_datastructure2022/tree/main/2_List/2_DoublyLinkedList) 구현하기, linked list 역순, [다항식의 덧셈](https://github.com/33bini/42-study_datastructure2022/tree/main/2_List/3_Polynomial)
<br>

## 비교
|    |배열 리스트                                                  |연결 리스트                                                   |
|:--:|:------------------------------------------------------------|:------------------------------------------------------------|
|장점|- 내적으로 배열을 사용하기 때문에 인덱스를 이용해서 접근이 빠르다. |- 동적으로 메모리 사용이 가능하다.<br> - 최대 원소 개수 지정이 불필요하다. <br>- 대용량 데이터 처리에 적합하다.|
|단점|- 배열 내의 데이터 이동 및 재구성이 어렵다.<br>- 동적으로 사용하기 힘들다.|- 구현이 어렵다.<br>- 탐색 연산의 시간 복잡도(O(n))가 좋지 않다.<br>-메모리를 추가적으로 사용해야 한다.<br>- 논리적 순서와 물리적 저장 순서가 일치하지 않는다.|