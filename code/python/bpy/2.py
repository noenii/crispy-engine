#cube spawner
import bpy

class AddCube(bpy.types.Operator):
    bl_idname = "object.add_cube"
    bl_label = "Add Cube"
    
    def execute(self, context):
        bpy.ops.mesh.primitive_cube_add(enter_editmode=False, align='WORLD', location=(0, 0, 0), scale=(1, 1, 1))
        self.report({'INFO'}, "Spawned a cube!")
        return {'FINISHED'}
    
def register():
    bpy.utils.register_class(AddCube)

def unregister():
    bpy.utils.unregister_class(AddCube)

if __name__ == "__main__":
    register()