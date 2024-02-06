
# 相關網頁

```cardlink
url: https://dl.acm.org/
title: "ACM Digital Library"
description: "ACM Digital Library Home page"
host: dl.acm.org
favicon: https://dl.acm.org/pb-assets/head-metadata/favicon-32x32-1574252172003.png
```

```cardlink
url: https://hackmd.io/MLPFFH8GTaiZNRc1JcYMIw?view
title: "Paper List - HackMD"
host: hackmd.io
favicon: https://hackmd.io/favicon.png
image: https://hackmd.io/images/media/HackMD-og.jpg
```

# 等級

[portal.core.edu.au/conf-ranks/](http://portal.core.edu.au/conf-ranks/)

```cardlink
url: https://www.ece.iastate.edu/~hongwei/group/miscl/ComputerSecurityConferences.htm
title: "Security Conference Ranking and Statistic"
host: www.ece.iastate.edu
```
https://www.ece.iastate.edu/~hongwei/group/miscl/ComputerSecurityConferences.htm

# Interesting Paper



## OP-TEE

- Intel: SGX
- ﻿﻿AMD: SEV
- ﻿﻿ARM: TrustZone
- ﻿﻿RISC-V: Sanctum, Keystone

Treat model

- ﻿﻿Secret leakage
- ﻿﻿Fully access to the CB interface (PLO) used for setting up enclaves (ex: by memory corruption)
- ﻿﻿Able to compromise peripherals

- ﻿﻿Assuming the hardware to be correct
- ﻿﻿• Excluding hardware flaws, physical access, physical side-channeling, malicious peripherals
- ﻿﻿Denial-of-Service (Dos)
- ﻿﻿Software-exploitation

有在研究的學長：浩洋

```dataview
table intro, author, done
from "paper"
where contains(tags, "OPTEE")
```

## Satellite
```dataview
table intro, author
from "paper"
where contains(tags, "SATELLITE")
```


## ALL
```dataview
table tags
from "paper"
```
