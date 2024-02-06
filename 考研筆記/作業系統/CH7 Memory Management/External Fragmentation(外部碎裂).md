External Fragmentation(外部碎裂)

> 定義：
> 在Contiguous Allocation 要求下，若所有holes size皆無法滿足process size 需求，但這些free holes 之total size卻>=process size，然而因為這些holes並不連續，故無法配置給此process行程memory space 浪費。

==memory 中的holes無法有效利用造成的。==
==通常外碎較為嚴重==