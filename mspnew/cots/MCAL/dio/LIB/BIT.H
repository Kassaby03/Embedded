#ifndef BIT_H_INCLUDED
#define BIT_H_INCLUDED

#define SET_BIT(Reg, BitNo) (Reg |=1<<BitNo)

#define CLR_BIT(Reg, BitNo) (Reg &=~(1<<BitNo))

#define TOG_BIT(Reg, BitNo) ((Reg) ^= (1<<(BitNo)))

#define GET_BIT(Reg, BitNo) ((Reg&(1<<BitNo))>>BitNo)

#define SET_BYTE(Reg, Val) (Reg = value)

#define WRT_BIT(Reg, BitNo, Val) ((Reg)= (((Reg)&(~(1<<(BitNo))))|((Val)<<(BitNo))))
#endif
