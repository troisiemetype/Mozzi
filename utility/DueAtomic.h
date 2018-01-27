#ifndef DUE_ATOMIC_H
#define DUE_ATOMIC_H

// This is a kind of hack: It is simpler to write this header file with definitions for ATOMIC from AVR
// Than to change the files using them one by one, with conditionnal test on the processor.

static __inline__ uint8_t __iSeiRetVal(void)
{
    cpu_irq_enable();
    return 1;
}
static __inline__ uint8_t __iCliRetVal(void)
{
    cpu_irq_disable();
    return 1;
}
static __inline__ void __iSeiParam(const uint8_t *__s)
{
    cpu_irq_enable();
    __asm__ volatile ("" ::: "memory");
    (void)__s;
}
static __inline__ void __iCliParam(const uint8_t *__s)
{
    cpu_irq_disable();
    __asm__ volatile ("" ::: "memory");
    (void)__s;
}
static __inline__ void __iRestore(const  uint8_t *__s)
{
    cpu_irq_restore(*__s);
    __asm__ volatile ("" ::: "memory");
}

#define ATOMIC_BLOCK(type) for ( type, __ToDo = __iCliRetVal(); __ToDo ; __ToDo = 0 )

#define NONATOMIC_BLOCK(type) for ( type, __ToDo = __iSeiRetVal(); __ToDo ;  __ToDo = 0 )

#define ATOMIC_RESTORESTATE uint8_t sreg_save __attribute__((__cleanup__(__iRestore))) = cpu_irq_save()

#define ATOMIC_FORCEON uint8_t sreg_save __attribute__((__cleanup__(__iSeiParam))) = 0

#define NONATOMIC_RESTORESTATE uint8_t sreg_save __attribute__((__cleanup__(__iRestore))) = cpu_irq_save()

#define NONATOMIC_FORCEOFF uint8_t sreg_save __attribute__((__cleanup__(__iCliParam))) = 0

#endif