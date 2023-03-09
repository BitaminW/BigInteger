# BigInteger Class

C++ BigInteger 클래스입니다.

<h3>간단한 사용 예제</h3>

ERROR
```cpp
	for (; i >= 0; i--) {
		temp = temp * 10 + left.m_value[i];
		for (j = 9; j * right > temp; j--);

		temp -= j * right;
		cat[lgcat++] = j;
	}

```
