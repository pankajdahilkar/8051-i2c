


 unsigned char bcd2bin (unsigned char val)
 { 
 return val - 6 * (val >> 4); 
 }
 unsigned char bin2bcd (unsigned char val) 
{
return val + 6 * (val / 10); 
}

