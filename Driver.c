#include <ntddk.h>

VOID Unload(IN PDRIVER_OBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);

    KeBugCheckEx(MANUALLY_INITIATED_CRASH, 0, 0, 0, 0);
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = Unload;
    DbgPrint("����̹��� �ε�Ǿ����ϴ�. ��ε�� ��� ��ũ���� �߻��մϴ�.\n");

    return STATUS_SUCCESS;
}
