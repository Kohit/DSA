#HashTable
---
##ά����ֵ��ӳ���ϵ:
```
- keysΪstring���͵����飬ÿһ���Ӧһ��key��ע�⵱ǰ�汾keyֻ����string����
- valuesΪ�������͵����飬ÿһ���value��key��Ӧ�� ע��values�������ɹ����ʱ��ȷ��
- ��keys[rank] -> values[rank]
```

##Ҫ�ҵ�������rank�������ṩ��hashcode�Լ�prob����
```
- hashcode��������key��Ӧ��hashcode����Ϊrank)�����ڿ��ܴ��ڳ�ͻ��Ϊ������prob
- prob�������ҵ���Ӧ��valueӦ�ڵ�λ�ã�ע���λ�õ�value����Ϊ�գ���ʱ���ص�rank����keys[rank] -> values[rank]
```

##Ϊ�˶�Ӧ���ϲ�����������keys�Լ�values�����ֱ���޸ķ���
```
- key��������keys[rank]������key
- Value��������values[rank]����key��Ӧ��value
- rank����ǰ��ķ����õ���ע���޸ĵ�ʱ��Ҫ��key��valueͬʱ�޸�
```

##Ϊ�˷��㣬[]��������������Ϸ���
```
- []������еĲ���Ϊkey�����Ϳ���Ϊstring����char *
- []��������ص���Values[rank]�����ã���������Ϊ��ֵʹ��
- foo[key] = value
```
---
##HashTable����������Ĵ�СΪM��M�����һ���������Ҹ����������4��3
����HashTable��ʹ�ÿ��Բο�test.cpp