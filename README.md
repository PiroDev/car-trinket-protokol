# Car-trinket protokol

The program emulates the work of the car trinket that opens the car using EDS in conditions where the communication channel is fully available to any listener (including for a long time and attempts). Also, the attacker can repeat the listened data.

## Installation

Download crypto++ library:

For Ubuntu:

`$ sudo apt install libcrypto++-dev`

Build project in project directory:

`$ make`

## Usage

`$ ./bin/trinket.exe`

## Output sample
```
______________
command unlock
___________________________________
trinket->car send data (HANDSHAKE): 
�g��b0837c9b4c962c22d2ff8b5441b7b45805887f051d39bf133b583baf6860unlockf
�S��.��E)�:
           R�a  ��i.(�Z1��+jD�ۉv�s�G�����S��?�8Z�Q�_{cޔ �+��Y��j�w,N��J��ׯ���/6���S9�0��5`K鹅���q��ka�
___________________________________
car->trinket send data (CHALLENGE): 
ng����F�&b��
\��X��`MKQv"T!Ĭ$ܓի6҇�~b��i$�]n�#seC~�-��N�p�)���!�_�w.5l>��U^ˢ����X7��� <�����D
��2i)x�}�ة�b=A���r��И�B'uQ�7m��@���?��م�
                                        0rZK����▒4&�J�W��O�a��������jȧ��F���dg�4a�YÜ������XT�*ߗ.�,��|R4{9�TD
__________________________________
trinket->car send data (RESPONSE): 
�%=Vb�����˜*�����ڦ�Y~� �o�M�1!�@^�`J�'ܣ�'D�lq������Z&�̫�▒�|�8G�e�-�$��A|�pg���GIR�yz��dH�:��
                                                                   ���A?:/Ev2%▒�Z~?Vl������:���7����e��z���z�P�ZDYOt����s]�xM��n�7��՞Of��y��"��c�؊X,�ATu�}��C6�7��=�l���u`ы�p+D�{�c��8t��[^zM�s�
______________________________
command unlock status: success
```
