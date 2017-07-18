using UnityEngine;
using System.Collections;

public class TreeMotion : MonoBehaviour {

    private int vanish;
    private bool hitflag;
    public float rot_x_def = 0;
    private int pos_rand;

    // Use this for initialization
    void Start () {
        vanish = -1;
        hitflag = false;
    }
	
	// Update is called once per frame
	void Update () {
        Vector3 pos = transform.position;
        Vector3 rot = transform.localEulerAngles;

        if (vanish < 0) vanish = -1;

        if (vanish == 0) {
            hitflag = false;
            pos_rand = Random.Range(0, 5);
            if (pos_rand == 0) pos.x += 2;
            if (pos_rand == 1) pos.x -= 2;
            if (pos_rand == 2) pos.z += 2;
            if (pos_rand == 3) pos.z -= 2;
        }
        vanish--;
        if (vanish > 0 && vanish < 130) pos.y = -200;
        
        if (hitflag == true) {
            pos.y += 0.5f;
            rot.z += 10;
        }
        else {
            pos.y = 0;
            rot.z = 0;
            rot.x = rot_x_def;
        }

        transform.position = pos;
        transform.localEulerAngles = rot;

    }
    void OnTriggerEnter(Collider hit) {

        if (hit.CompareTag("Player")) {
            hitflag = true;
            vanish = 150;
        }
    }
}
