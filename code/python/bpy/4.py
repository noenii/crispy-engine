#my own shader (blender)
import bpy

bpy.types.Scene.lighting_color = bpy.props.FloatVectorProperty(
    name="Color",
    subtype='COLOR',
    size=3,
    min=0.0,
    max=1.0,
    default=(0.5, 0.5, 0.5),
    description="Pick a color for all active object's materials"
)

class ShaderUpdater(bpy.types.Operator):
    bl_idname = "object.shader_updater_internal"
    bl_label = "Shader Updater"
    bl_description = "Update lighting of all materials"
    bl_options = {'REGISTER', 'UNDO'}

    def execute(self, context):
        
        for obj in context.selected_objects:
            if obj.type != 'MESH':
                continue
            for slot in obj.material_slots:
                mat = slot.material
                print(mat.name)
                if not mat or not mat.use_nodes:
                    continue
                nodes = mat.node_tree.nodes
                for node in nodes:
                    if node.type == "GROUP" and node.name == "Group.001":
                        bpy.data.materials[mat.name].node_tree.nodes["Mix"].inputs[7].default_value = (*bpy.context.scene.lighting_color, 1.0)
        self.report({'INFO'}, "All materials updated")
        return {'FINISHED'}

class ShaderPanel(bpy.types.Panel):
    bl_idname = "OBJECT_PT_shader_panel"
    bl_label = "Shader Panel"
    bl_space_type = 'VIEW_3D'
    bl_region_type = 'UI'
    bl_category = "Shader"

    def draw(self, context):
        layout = self.layout
        scene = context.scene

        layout.prop(scene, "lighting_color", text="Color")

        row = self.layout.row()
        row.operator("object.shader_updater_internal", text="Apply")

def register():
    bpy.utils.register_class(ShaderUpdater)
    bpy.utils.register_class(ShaderPanel)

def unregister():
    bpy.utils.unregister_class(ShaderUpdater)
    bpy.utils.unregister_class(ShaderPanel)

if __name__ == "__main__":
    register()