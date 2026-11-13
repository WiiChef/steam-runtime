package android.annotation;
import java.lang.annotation.*;
@Target({ElementType.TYPE_USE, ElementType.TYPE, ElementType.FIELD, ElementType.METHOD, ElementType.CONSTRUCTOR})
public @interface SystemApi { Client client(); enum Client { MODULE_LIBRARIES } }
