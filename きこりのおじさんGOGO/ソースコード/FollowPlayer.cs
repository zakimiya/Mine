using UnityEngine;
using System.Collections;

public class FollowPlayer : MonoBehaviour
{
    public Transform target;    // ターゲットへの参照
    private Vector3 offset;     // 相対座標

    void Start()
    {
        //自分自身とtargetとの相対距離を求める
        offset = GetComponent<Transform>().position - target.position;
    }

    void Update()
    {/*
        Vector3 pos = transform.position;
        // 自分自身の座標に、targetの座標に相対座標を足した値を設定する

        if (Input.GetKey(KeyCode.Space))
        {
            pos.x = 0;
            pos.y = 0;
            pos.z = 0;
        }
        else*/
            GetComponent<Transform>().position = target.position + offset;

     //   transform.position = pos;
    }
}