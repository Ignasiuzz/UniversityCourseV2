# UniversityCourseV2
Objektinio programavimo antroji užduotis

# Spartos analize  
## Be oprimizatoriaus
100.000 studentų  
Struct. Student sorting to two groups took 0.0304037 seconds.  
Class. Student sorting to two groups took 0.0443925 seconds.  
1.000.000 studentų   
Struct. Student sorting to two groups took 0.319136 seconds.  
Class. Student sorting to two groups took 0.600509 seconds.  

## Kompiliatoriaus optimizavimo lygiai 
### 100.000 studentų
| Optimization | Struct | Class | File size (KB) | Struct | Class |
| :---: | :---: | :---: | :---: | :---: | :---: |
| O1 | 0.0117796 seconds. | 0.0195176 seconds. |O1| 262 | 254 |
| O2 | 0.0114957 seconds. | 0.0205766 seconds. |O2| 266 | 256 |
| O3 | 0.0108180 seconds. | 0.0202935 seconds. |O3| 264 | 259 |


### 1.000.000 studentų
| Optimization | Struct | Class | File size (KB) | Struct | Class |
| :---: | :---: | :---: | :---: | :---: | :---: |
| O1 | 0.127661 seconds. | 0.345793 seconds. |O1| 262 | 254 |
| O2 | 0.115778 seconds. | 0.339243 seconds. |O2| 266 | 256 | 
| O3 | 0.115472 seconds. | 0.333918 seconds. |O3| 264 | 259 |
