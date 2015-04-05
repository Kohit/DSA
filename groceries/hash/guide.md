#HashTable
---
##维护键值的映射关系:
```
- keys为string类型的数组，每一项对应一个key，注意当前版本key只能是string类型
- values为任意类型的数组，每一项的value与key对应， 注意values的类型由构造的时候确定
- 即keys[rank] -> values[rank]
```

##要找到上述的rank，这里提供了hashcode以及prob函数
```
- hashcode函数返回key对应的hashcode（记为rank)，由于可能存在冲突，为此引入prob
- prob函数将找到对应的value应在的位置，注意该位置的value可能为空，此时返回的rank满足keys[rank] -> values[rank]
```

##为了对应以上操作，开放了keys以及values数组的直接修改方法
```
- key函数返回keys[rank]，即键key
- Value函数返回values[rank]，即key对应的value
- rank可由前面的方法得到，注意修改的时候定要将key和value同时修改
```

##为了方便，[]运算符整合了以上方法
```
- []运算符中的参数为key，类型可以为string或者char *
- []运算符返回的是Values[rank]的引用，即可以作为左值使用
- foo[key] = value
```
---
##HashTable的两个数组的大小为M，M最好是一个素数，且该素数满足除4余3
关于HashTable的使用可以参考test.cpp