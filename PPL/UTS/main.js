var id_kec = msg.payload.id_kec || null;
var fields = msg.payload.fields || ["id_desa", "id_kec", "nm_desa", "st_desa"];

if (!id_kec) {
    msg.payload = { error: "id_kec diperlukan" };
    return msg;
}

var allowedFields = ["id_desa", "id_kec", "nm_desa", "st_desa"];
var selectedFields = fields.filter(f => allowedFields.includes(f));

if (selectedFields.length === 0) {
    msg.payload = { error: "Kolom tidak valid" };
    return msg;
}

var query = "SELECT " + selectedFields.join(", ") + " FROM desa WHERE id_kec = '" + id_kec + "'";
msg.topic = query;
return msg;